/*
 * UrlProvider.h
 *
 *  Created on: Mar 22, 2018
 *      Author: deth
 */

#ifndef URLPROVIDER_H_
#define URLPROVIDER_H_

#include "UrlDescriptor.h"
#include <vector>

/**
 * Interface responsible for providing source URLs, be it file, centralized repository, etc.
 */
class UrlProvider
{
public:
	virtual ~UrlProvider(){}
	/**
	 * Returns available or pre-configured pack of URLs
	 * @return
	 */
	virtual std::vector<UrlDescriptor> get_url_pack() = 0;
};


#endif /* URLPROVIDER_H_ */
