/*
 * PageDownloader.h
 *
 *  Created on: Mar 23, 2018
 *      Author: deth
 */

#ifndef PAGEDOWNLOADER_H_
#define PAGEDOWNLOADER_H_

#include "../contracts/Downloader.h"
#include "../network/NetSessionFactory.h"
#include <condition_variable>
#include <mutex>
#include <atomic>

/**
 * COncrete implementation for textual web content downloading
 */
class PageDownloader: public Downloader
{
public:
  /**
   * ctor
   * @param netFactory - reference to session factory
   * @param maxConnections - maximum downloads allowed to run at the same time
   */
	PageDownloader(network::NetSessionFactory& netFactory, uint8_t maxConnections);
	virtual ~PageDownloader();

	virtual void submit_for_download_async(UrlDescriptor const& url, std::function<void(std::string&&)> content) override;

protected:
	network::NetSessionFactory& m_netFactory;
	uint8_t m_maxConnections = 0;
	std::atomic_uint8_t m_inUse;
	std::mutex m_mut;
	std::condition_variable m_connectionReady;
};

#endif /* PAGEDOWNLOADER_H_ */
