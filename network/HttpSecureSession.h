/*
 * HttpSecureSession.h
 *
 *  Created on: Mar 23, 2018
 *      Author: deth
 */

#ifndef HTTPSECURESESSION_H_
#define HTTPSECURESESSION_H_

#include "NetSession.h"
#include <memory>
#include <string>
#include <boost/asio.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ssl.hpp>

namespace network
{

using boost::asio::ip::tcp;
namespace ssl = boost::asio::ssl;

/**
 * Concrete SSL aware NetSession implementation, based on boost::asio
 */
class HttpSecureSession : public NetSession,
						  public std::enable_shared_from_this<HttpSecureSession>
{
public:
	HttpSecureSession(boost::asio::io_service& io_service,
			boost::asio::ssl::context& context);
	virtual ~HttpSecureSession();

	virtual void get_async(std::string const& host, std::string const& path,
				std::function<void(std::string&&)> readyCallback) override;

private:
	void handle_resolve(const boost::system::error_code& err, tcp::resolver::iterator endpointIter);
	void handle_connect(const boost::system::error_code& err);
	void handle_handshake(const boost::system::error_code& err);
	void handle_write_request(const boost::system::error_code& err);
	void handle_read_status(const boost::system::error_code& err);
	void handle_read_content(const boost::system::error_code& err);

	std::function<void(std::string&&)> m_readyCbck;
	std::string m_host;
	std::stringstream m_out;
	tcp::resolver m_resolver;
	boost::asio::ssl::stream<tcp::socket> m_socket;
	boost::asio::streambuf m_request;
	boost::asio::streambuf m_response;
};

} /* namespace utility */

#endif /* HTTPSECURESESSION_H_ */
