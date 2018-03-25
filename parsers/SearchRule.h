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

/**
 * Enumerates available text search mechanisms
 */
enum class SearchPolicyType
{
	SIMPLE,
	REGEX, //etc.
};

/**
 * Describes a search rule for particular data item
 */
struct SearchRule
{
	std::string data_id;                  //data item identifier
	std::string search_template;          //search pattern to be used with particular search policy
	SearchPolicyType search_policy_type;  //the type of search policy
};

}
#endif /* SEARCHRULE_H_ */
