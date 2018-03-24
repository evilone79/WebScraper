/*
 * SearchPolicyFactory.h
 *
 *  Created on: Mar 24, 2018
 *      Author: deth
 */

#ifndef SEARCHPOLICYFACTORY_H_
#define SEARCHPOLICYFACTORY_H_

#include "SearchPolicy.h"
#include <memory>

namespace parsers
{

class SearchPolicyFactory
{
public:
	std::shared_ptr<SearchPolicy> get_search_policy(SearchPolicyType policyType);
};

} /* namespace parsers */

#endif /* SEARCHPOLICYFACTORY_H_ */
