/*
 * SearchPolicyFactory.cpp
 *
 *  Created on: Mar 24, 2018
 *      Author: deth
 */

#include "SearchPolicyFactory.h"
#include "RegexSearchPolicy.h"

namespace parsers
{
	std::shared_ptr<SearchPolicy> parsers::SearchPolicyFactory::get_search_policy(
			SearchPolicyType policyType)
	{
		switch(policyType){
		case SearchPolicyType::REGEX:
			return std::make_shared<RegexSearchPolicy>();
		}
		return nullptr;
	}
} /* namespace parsers */


