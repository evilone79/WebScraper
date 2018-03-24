/*
 * PageDownloader.cpp
 *
 *  Created on: Mar 23, 2018
 *      Author: deth
 */

#include "../main/PageDownloader.h"


using namespace network;

PageDownloader::PageDownloader(NetSessionFactory& netFactory, uint8_t maxConnections)
	: m_netFactory(netFactory),
	  m_maxConnections(maxConnections),
	  m_inUse(0)
{
}

PageDownloader::~PageDownloader()
{
}

void PageDownloader::submit_for_download_async(const UrlDescriptor& url,
		std::function<void(std::string&&)> on_content)
{
	std::unique_lock<std::mutex> lock(m_mut);
	m_connectionReady.wait(lock, [this]{ return m_inUse.load() < m_maxConnections;});
	++m_inUse;
	auto session = m_netFactory.create_session();
	session->get_async(url.hostname, url.path, [&, on_content](auto&& content){
		--m_inUse;
		m_connectionReady.notify_one();
		on_content(std::forward<decltype(content)>(content));
	});

}
