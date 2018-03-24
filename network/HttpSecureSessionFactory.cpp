/*
 * HttpSecureSessionFactory.cpp
 *
 *  Created on: Mar 23, 2018
 *      Author: deth
 */

#include "HttpSecureSessionFactory.h"
#include "HttpSecureSession.h"

namespace network
{

HttpSecureSessionFactory::HttpSecureSessionFactory() :
		m_ctx(boost::asio::ssl::context::sslv23),
		m_stop(false)
{
	m_ctx.set_default_verify_paths();
	m_poller = std::thread([this]
	{
		while(!m_stop)
		{
			m_ioService.reset();
			m_ioService.run();
		}
	});
}

HttpSecureSessionFactory::~HttpSecureSessionFactory()
{
	m_stop = true;
	m_ioService.stop();
	m_poller.join();
}

std::shared_ptr<NetSession> HttpSecureSessionFactory::create_session()
{
	return std::make_shared<HttpSecureSession>(m_ioService, m_ctx);
}

} /* namespace network */
