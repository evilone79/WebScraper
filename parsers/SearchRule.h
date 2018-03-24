/*
 * ParseRule.h
 *
 *  Created on: Mar 23, 2018
 *      Author: deth
 */

#ifndef SEARCHRULE_H_
#define SEARCHRULE_H_

#include <string>

namespace parsers
{

enum class SearchPolicyType
{
	SIMPLE,
	REGEX, //etc.
};
struct SearchRule
{
	std::string data_id;
	std::string search_template;
	SearchPolicyType search_policy_type;
};

}
#endif /* SEARCHRULE_H_ */
