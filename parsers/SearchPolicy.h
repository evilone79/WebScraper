/*
 * SearchPolicy.h
 *
 *  Created on: Mar 24, 2018
 *      Author: deth
 */

#ifndef SEARCHPOLICY_H_
#define SEARCHPOLICY_H_

#include <string>
#include "SearchRule.h"

namespace parsers
{
struct SearchResult
{
	std::string data;
	bool found = false;
};

class SearchPolicy
{
public:
	virtual ~SearchPolicy() {}
	/**
	 * Performs the actual search on given text using the template provided
	 * @param content
	 * @param searchTemplate
	 * @return SearchResult
	 */
	virtual  apply(std::string const& content,  std::string searchTemplate) = 0;
};

}
#endif /* SEARCHPOLICY_H_ */
