/*
 * ProductDalMySql.h
 *
 *  Created on: Mar 24, 2018
 *      Author: deth
 */

#ifndef PRODUCTDALMYSQL_H_
#define PRODUCTDALMYSQL_H_

#include "ProductDal.h"

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>


namespace dal
{

class ProductDalMySql: public virtual ProductDal
{
public:
	ProductDalMySql();
	virtual ~ProductDalMySql();

	virtual void insert_product(Product const& product) override;

private:

	sql::Driver* m_driver;
	std::unique_ptr<sql::Connection> m_con;
};



} /* namespace dal */

#endif /* PRODUCTDALMYSQL_H_ */
