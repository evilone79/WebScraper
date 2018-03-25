/*
 * RegexSearchPolicy.h
 *
 *  Created on: Mar 24, 2018
 *      Author: deth
 */

#ifndef REGEXSEARCHPOLICY_H_
#define REGEXSEARCHPOLICY_H_

#include "SearchPolicy.h"

namespace parsers
{

/**
 * Concrete policy for regex based search
 */
class RegexSearchPolicy : public SearchPolicy
{
public:
	RegexSearchPolicy();
	virtual ~RegexSearchPolicy();

	virtual SearchResult apply(std::string const& content,  std::string searchTemplate) override;
};

} /* namespace parsers */

#endif /* REGEXSEARCHPOLICY_H_ */
