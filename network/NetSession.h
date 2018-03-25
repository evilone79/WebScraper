/*
 * NetSession.h
 *
 *  Created on: Mar 22, 2018
 *      Author: deth
 */

#ifndef NETSESSION_H_
#define NETSESSION_H_

#include <string>
#include <functional>

namespace network
{
/**
 * Abstract interface for asynchronous HTTP client session
 */
class NetSession
{
public:
  /**
   * Launches asynchronous GET operation for host and path provided
   * @param host
   * @param path
   * @param readyCallback - will be invoked upon finish of GET operation
   */
	virtual void get_async(std::string const& host, std::string const& path,
			std::function<void(std::string&&)> readyCallback) = 0;
	virtual ~NetSession(){}
};

}
#endif /* NETSESSION_H_ */
