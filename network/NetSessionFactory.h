/*
 * NetSessionFactory.h
 *
 *  Created on: Mar 23, 2018
 *      Author: deth
 */

#ifndef NETSESSIONFACTORY_H_
#define NETSESSIONFACTORY_H_

#include "NetSession.h"
#include <memory>

namespace network
{

/**
 * Abstract factory for specific NetSession implementation
 */
class NetSessionFactory
{
public:
  /**
   * Creates an instance of specific NetSession implementation
   * @return
   */
	virtual std::shared_ptr<NetSession> create_session() = 0;
	virtual ~NetSessionFactory(){}
};

}
#endif /* NETSESSIONFACTORY_H_ */
