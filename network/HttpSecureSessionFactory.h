/*
 * HttpSecureSessionFactory.h
 *
 *  Created on: Mar 23, 2018
 *      Author: deth
 */

#ifndef HTTPSECURESESSIONFACTORY_H_
#define HTTPSECURESESSIONFACTORY_H_

#include "NetSessionFactory.h"
#include <boost/asio/io_service.hpp>
#include <boost/asio/ssl.hpp>
#include <thread>
#include <atomic>

namespace network
{

class HttpSecureSessionFactory : public NetSessionFactory
{
public:
	HttpSecureSessionFactory();
	virtual ~HttpSecureSessionFactory();

	std::shared_ptr<NetSession> create_session() override;

protected:
	boost::asio::ssl::context m_ctx;
	boost::asio::io_service m_ioService;
	std::thread m_poller;
	std::atomic_bool m_stop;
};

} /* namespace network */

#endif /* HTTPSECURESESSIONFACTORY_H_ */
