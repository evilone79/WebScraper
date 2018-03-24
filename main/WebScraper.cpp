//============================================================================
// Name        : WebScraper.cpp
// Author      : me
// Version     :
// Copyright   : Your copyright notice
// Description : Programming excersise for FreshKeep
//============================================================================

#include <iostream>
using namespace std;

#include "../parsers/SearchPolicyFactory.h"
#include "../dal/ProductDalMySql.h"
#include "../dal/ProductDalDummy.h"
#include "PageDownloader.h"
#include "ProductFinder.h"
#include "../utility/TaskRunner.h"
#include "../network/HttpSecureSessionFactory.h"
#include "SearchRuleCache.h"
#include "SimpleUrlProvider.h"


using namespace parsers;
using namespace dal;
using namespace utility;
using namespace network;
using namespace std;


int main() {
	cout << "!!!Hello World!!! We're gonna scrape it hard!" << endl;

	SimpleUrlProvider urlProvider;
	HttpSecureSessionFactory sessionFact;
	PageDownloader downloader(sessionFact, 10);
	//ProductDalMySql dal;
	ProductDalDummy dal;
	SearchRuleCache ruleCache;
	SearchPolicyFactory policyFactory;
	TaskRunner runner;

	ruleCache.preload_ruleset();


	auto urls = urlProvider.get_url_pack();
	for(auto& url : urls)
	{
		runner.submit([=]{ cout << "Handling site: " << url.hostname << ", path: " << url.path << "\n"; });

		downloader.submit_for_download_async(url, [&](std::string&& page)
		{
			ProductFinder pf(std::forward<std::string>(page),
					runner,
					url.hostname,
					ruleCache.get_ruleset_by_host(url.hostname),
					policyFactory);
			pf.on_product_ready([&](Product&& prod)
			{
				runner.submit([&, prod]
				{
					dal.insert_product(prod);
				});
			});
			runner.submit([=]() mutable { pf.run_search(); });
		});
	}

	cout << "Finished parsing\n";

	std::cin.get();
	cout << "Exiting...\n";
	return 0;
}
