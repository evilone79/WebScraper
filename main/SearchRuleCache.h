/*
 * SearchRuleCache.h
 *
 *  Created on: Mar 24, 2018
 *      Author: deth
 */

#ifndef SEARCHRULECACHE_H_
#define SEARCHRULECACHE_H_

#include "../parsers/SearchRule.h"
#include <unordered_map>
#include <vector>

class SearchRuleCache
{
public:
	SearchRuleCache();
	virtual ~SearchRuleCache();

	std::vector<parsers::SearchRule> get_ruleset_by_host(std::string const& host);
	void preload_ruleset();

private:
	std::unordered_map<std::string, std::vector<parsers::SearchRule>> m_ruleSets;
};

#endif /* SEARCHRULECACHE_H_ */
