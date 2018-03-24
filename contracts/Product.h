/*
 * Product.h
 *
 *  Created on: Mar 24, 2018
 *      Author: deth
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_

#include "DataDescriptor.h"
#include <unordered_map>
#include <sstream>

class Product
{
	using field_container_t = std::unordered_map<std::string, std::string>;
public:
	Product(std::string const& website) : m_sourceWebsite(website) {}
	void add_field(std::string name, std::string&& data)
	{
		if(m_dataFields.find(name) == m_dataFields.end())
		{
			m_dataFields[name] = std::forward<std::string>(data);
		}
	}
	const field_container_t& fields() const {return m_dataFields;}
	std::string website() const { return m_sourceWebsite; }

	std::string debug_print() const
	{
		std::stringstream ss;
		ss << "Product from " << m_sourceWebsite << "\n";
		for(auto& f : m_dataFields)
		{
			ss << f.first << " : " << f.second << "\n";
		}
		return ss.str();
	}
private:
	std::string m_sourceWebsite;
	field_container_t m_dataFields;
};

#endif /* PRODUCT_H_ */
