/*
 * ProductDalMySql.cpp
 *
 *  Created on: Mar 24, 2018
 *      Author: deth
 */

#include "ProductDalMySql.h"

#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <sstream>
#include <iostream>

namespace dal
{

ProductDalMySql::ProductDalMySql()
{
	try
	{
		m_driver = sql::mysql::get_driver_instance();
		m_con = std::unique_ptr<sql::Connection>(
				m_driver->connect("tcp://127.0.0.1:3306", "root", "root"));
		m_con->setSchema("ProductDB");
	} catch (sql::SQLException &e)
	{
		//log properly and rethrow
		throw;
	}
}

ProductDalMySql::~ProductDalMySql()
{
	// TODO Auto-generated destructor stub
}

void ProductDalMySql::insert_product(const Product& product)
{
	try
	{
		//Im assuming here data name reflects its column name
		std::stringstream query;
		query << "INSERT INTO Products (website";
		for(auto& field : product.fields())
		{
			query << "," << field.first;
		}
		query << ") VALUES ('" << product.website() << "'";
		for(auto& field : product.fields())
		{
			query << ",'" << field.second << "'";
		}
		query << ");";

		std::cout << "Rolling DB insert: \n" << query.str();
		auto stmt = std::unique_ptr<sql::Statement>(m_con->createStatement());
		auto res = std::unique_ptr<sql::ResultSet>(stmt->executeQuery(query.str()));

	} catch (sql::SQLException &e)
	{
		//log properly
	}
}

} /* namespace dal */
