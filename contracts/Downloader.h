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

/**
 * Abstract interface for asynchronous content downloading
 */
class Downloader
{
public:
  /**
   * Launches an async download operation
   * @param url - source URL
   * @param content - download completion callback, the downloaded content will be fed into
   */
	virtual void submit_for_download_async(UrlDescriptor const& url, std::function<void(std::string&&)> content) = 0;

};


#endif /* DOWNLOADER_H_ */
