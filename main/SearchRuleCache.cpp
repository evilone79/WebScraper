/*
 * SearchRuleCache.cpp
 *
 *  Created on: Mar 24, 2018
 *      Author: deth
 */

#include "SearchRuleCache.h"
#include <boost/algorithm/string.hpp>

using namespace parsers;

SearchRuleCache::SearchRuleCache()
{
	// TODO Auto-generated constructor stub

}

SearchRuleCache::~SearchRuleCache()
{
	// TODO Auto-generated destructor stub
}

std::vector<SearchRule> SearchRuleCache::get_ruleset_by_host(const std::string& host)
{
	auto hostUpper =boost::to_upper_copy(host);
	if(m_ruleSets.find(hostUpper) != m_ruleSets.end())
	{
		return m_ruleSets[hostUpper];
	}
	return {};
}

void SearchRuleCache::preload_ruleset()
{
	//this method will basically load all defined data search rules for product, currently defined in repository (DB, file, etc.)
	//this is just a testing stub
	m_ruleSets.emplace(std::make_pair("WWW.EBAY.COM", std::vector<SearchRule>
	{
		{"title", "<title>(.*?)</title>", SearchPolicyType::REGEX},
		{"price", "", SearchPolicyType::REGEX}
	}));
	m_ruleSets.emplace(std::make_pair("WWW.AMAZON.COM", std::vector<SearchRule>
	{
		{"title", "<title>(.*?)</title>", SearchPolicyType::REGEX},
		{"price", "", SearchPolicyType::REGEX}
	}));


}
