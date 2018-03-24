/*
 * ProductFinder.cpp
 *
 *  Created on: Mar 24, 2018
 *      Author: deth
 */

#include "../main/ProductFinder.h"

#include <future>

ProductFinder::ProductFinder(std::string&& content,
		utility::TaskRunner& runner,
		std::string webSite,
		std::vector<parsers::SearchRule> rules,
		parsers::SearchPolicyFactory& policyFact) :
	m_content(std::forward<std::string>(content)),
	m_policyFact(policyFact),
	m_rules(rules),
	m_runner(runner),
	m_webSite(webSite)

{
	// TODO Auto-generated constructor stub

}

ProductFinder::~ProductFinder()
{
}

void ProductFinder::run_search()
{
	using data_item_t = std::pair<std::string, parsers::SearchResult>; //key:value
	std::vector<std::promise<data_item_t>> promises(m_rules.size());
	std::vector<std::future<data_item_t>> futures;

	//launch parallel searches for each search rule
	for(auto i = 0; i < m_rules.size(); ++i)
	{
		auto& rule = m_rules[i];
		auto searchPolicy = m_policyFact.get_search_policy(rule.search_policy_type);
		futures.emplace_back(promises[i].get_future());
		m_runner.submit([&, i]()
				{
					auto result = searchPolicy->apply(m_content, rule.search_template);
					promises[i].set_value(std::make_pair(rule.data_id, std::move(result)));
				});
	}

	//collect search results
	Product prod(m_webSite);
	for(auto& f : futures)
	{
		auto field = f.get();
		if(field.second.found)
		{
			prod.add_field(field.first, std::move(field.second.data));
		}
	}
	if(m_onProduct)
		m_onProduct(std::move(prod));
}

void ProductFinder::on_product_ready(std::function<void(Product&&)> onProduct)
{
	m_onProduct = onProduct;
}

