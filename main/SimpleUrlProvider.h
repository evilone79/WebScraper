/*
 * SimpleUrlProvider.h
 *
 *  Created on: Mar 24, 2018
 *      Author: deth
 */

#ifndef SIMPLEURLPROVIDER_H_
#define SIMPLEURLPROVIDER_H_

#include "../contracts/UrlProvider.h"

/**
 * Dummy implementation of URL provider for demonstration purposes
 */
class SimpleUrlProvider : public UrlProvider
{
public:
	SimpleUrlProvider();
	virtual ~SimpleUrlProvider();

	virtual std::vector<UrlDescriptor> get_url_pack() override;

private:
};

#endif /* SIMPLEURLPROVIDER_H_ */
