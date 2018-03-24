/*
 * Downloader.h
 *
 *  Created on: Mar 22, 2018
 *      Author: deth
 */

#ifndef DOWNLOADER_H_
#define DOWNLOADER_H_

#include "UrlDescriptor.h"
#include <functional>

class Downloader
{
public:
	virtual void submit_for_download_async(UrlDescriptor const& url, std::function<void(std::string&&)> content) = 0;

};


#endif /* DOWNLOADER_H_ */
