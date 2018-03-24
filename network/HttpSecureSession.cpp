/*
 * HttpSecureSession.cpp
 *
 *  Created on: Mar 23, 2018
 *      Author: deth
 */

#include "HttpSecureSession.h"
#include <iostream>

namespace network
{

HttpSecureSession::HttpSecureSession(
		boost::asio::io_service& io_service,
		boost::asio::ssl::context& context)
		:
		m_resolver(io_service), m_socket(io_service, context)
{}

HttpSecureSession::~HttpSecureSession()
{
	// TODO Auto-generated destructor stub
}

void HttpSecureSession::get_async(
		const std::string& host,
		const std::string& path,
		std::function<void(std::string&&)> readyCallback)
{
	m_host = host;
	m_readyCbck = readyCallback;
	// We specify the "Connection: close" header so that the
	// server will close the socket after transmitting the response. This will
	// allow us to treat all data up until the EOF as the content.
	std::ostream request_stream(&m_request);
	request_stream << "GET " << path << " HTTP/1.0\r\n";
	request_stream << "Host: " << host << "\r\n";
	request_stream << "Accept: */*\r\n";
	request_stream << "Connection: close\r\n\r\n";

	// Start an asynchronous resolve to translate the server and service names
	// into a list of endpoints.
	tcp::resolver::query query(host, "https");
	auto self = shared_from_this();
	m_resolver.async_resolve(query, [this, self](auto ec, auto iter)
	{
		handle_resolve(ec, iter);
	});
}

void HttpSecureSession::handle_resolve(const boost::system::error_code& err,
		tcp::resolver::iterator endpointIter)
{
	if (!err)
	{
		m_socket.set_verify_mode(ssl::verify_none);
		m_socket.set_verify_callback(ssl::rfc2818_verification(m_host));
		auto self = shared_from_this();
		boost::asio::async_connect(m_socket.lowest_layer(), endpointIter,
				[this, self](auto& ec, auto iter)
				{
					handle_connect(ec);
				});
	}
	else
	{
		std::cout << "resolving failed: " << err.message() << "\n";
	}
}

void HttpSecureSession::handle_connect(const boost::system::error_code& err)
{
	if (!err)
	{
		auto self = shared_from_this();
		m_socket.async_handshake(ssl::stream_base::client, [this, self](auto& ec)
		{
			handle_handshake(ec);
		});
	}
	else
	{
		std::cout << "connecting failed: " << err.message() << "\n";
	}
}

void HttpSecureSession::handle_handshake(const boost::system::error_code& err)
{
	if (!err)
	{
		const char* header = boost::asio::buffer_cast<const char*>(m_request.data());
		auto self = shared_from_this();
		boost::asio::async_write(m_socket, m_request,
				[this, self](auto& ec, auto written)
				{
					handle_write_request(ec);
				});
	}
	else
	{
		std::cout << "handshake failed: " << err.message() << "\n";
	}
}

void HttpSecureSession::handle_write_request(const boost::system::error_code& err)
{
	if (!err)
	{
		// Read the response
		auto self = shared_from_this();
		boost::asio::async_read_until(m_socket, m_response, "\r\n",
				[this, self](auto& ec, auto written)
				{
					handle_read_status(ec);
				});
	}
	else
	{
		std::cout << "write request failed: " << err.message() << "\n";
	}
}

void HttpSecureSession::handle_read_status(const boost::system::error_code& err)
{
	if (!err)
	{
		// Check that response is OK.
		std::istream response_stream(&m_response);
		std::string http_version;
		response_stream >> http_version;
		unsigned int status_code;
		response_stream >> status_code;
		std::string status_message;
		std::getline(response_stream, status_message);
		if (!response_stream || http_version.substr(0, 5) != "HTTP/")
		{
			std::cout << "Invalid response\n";
			return;
		}
		if (status_code != 200)
		{
			std::cout << "Response returned with status code " << status_code << "\n";
			//Log  status_code << "\n";
			return;
		}
		// Read the response headers, which are terminated by a blank line.
		auto self = shared_from_this();
		boost::asio::async_read_until(m_socket, m_response, "\r\n\r\n",
				[this, self](auto& ec, auto read)
				{
					handle_read_content(ec);
				});
	}
	else
	{
		std::cout << "Read status failed: " << err.message() << "\n";
	}
}



void HttpSecureSession::handle_read_content(
		const boost::system::error_code& err)
{
	if (!err)
	{
		// Write all of the data that has been read so far.
		m_out << &m_response;

		// Continue reading remaining data until EOF.
		auto self = shared_from_this();
		boost::asio::async_read(m_socket, m_response,
				boost::asio::transfer_at_least(1), [this, self](auto& ec, auto read)
				{
					handle_read_content(ec);
				});
	}
	else
	{
		if (err != boost::asio::error::eof)
		{
			//log error err.message()
			return;
		}
		if(m_readyCbck)
			m_readyCbck(std::move(m_out.str()));
	}

}

} /* namespace utility */
