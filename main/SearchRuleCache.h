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

/**
 * Component responsible for loading and caching of search rule sets from dedicated storage
 */
class SearchRuleCache
{
public:
	SearchRuleCache();
	virtual ~SearchRuleCache();

	/**
	 * Returns a rule set for particular host
	 * @param host
	 * @return
	 */
	std::vector<parsers::SearchRule> get_ruleset_by_host(std::string const& host);
	void preload_ruleset();

private:
	std::unordered_map<std::string, std::vector<parsers::SearchRule>> m_ruleSets;
};

#endif /* SEARCHRULECACHE_H_ */
