/*
 * RegexSearchPolicy.cpp
 *
 *  Created on: Mar 24, 2018
 *      Author: deth
 */

#include "RegexSearchPolicy.h"
#include <regex>

namespace parsers
{

RegexSearchPolicy::RegexSearchPolicy()
{
}

RegexSearchPolicy::~RegexSearchPolicy()
{	
}

SearchResult RegexSearchPolicy::apply(std::string const& content, std::string searchTemplate)
{
	std::regex rgx(searchTemplate);
	std::smatch match;

	if (std::regex_search(content.begin(), content.end(), match, rgx))
		return {match[1], true};

	return {};
}

} /* namespace parsers */
