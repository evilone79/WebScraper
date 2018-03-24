/*
 * ProductFinder.h
 *
 *  Created on: Mar 24, 2018
 *      Author: deth
 */

#ifndef PRODUCTFINDER_H_
#define PRODUCTFINDER_H_

#include "../dal/ProductDal.h"
#include "../utility/TaskRunner.h"
#include "../parsers/SearchRule.h"
#include "../parsers/SearchPolicyFactory.h"
#include <vector>


class ProductFinder
{
public:
	using product_callback_t = std::function<void(Product&&)>;
	ProductFinder(std::string&& content,
			utility::TaskRunner& runner,
			std::string webSite,
			std::vector<parsers::SearchRule> rules,
			parsers::SearchPolicyFactory& policyFact
			);
	virtual ~ProductFinder();

	void run_search();
	void on_product_ready(product_callback_t onProduct);

protected:

	std::string m_content;
	utility::TaskRunner& m_runner;
	std::string m_webSite;
	std::vector<parsers::SearchRule> m_rules;
	parsers::SearchPolicyFactory& m_policyFact;
	product_callback_t m_onProduct;
};

#endif /* PRODUCTFINDER_H_ */
