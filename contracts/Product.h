/*
 * Product.h
 *
 *  Created on: Mar 24, 2018
 *      Author: deth
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_


#include <unordered_map>
#include <sstream>

/**
 * Product entity. (code is inlined for brevity)
 */
class Product
{
	using field_container_t = std::unordered_map<std::string, std::string>;
public:
	Product(std::string const& website) : m_sourceWebsite(website) {}

	/**
	 * Inserts product related field data
	 * @param name
	 * @param data
	 */
	void add_field(std::string name, std::string&& data)
	{
		if(m_dataFields.find(name) == m_dataFields.end())
		{
			m_dataFields[name] = std::forward<std::string>(data);
		}
	}
	/**
	 * Returns reference to internal fields container
	 * @return
	 */
	const field_container_t& fields() const {return m_dataFields;}

	/**
	 * Gets the website, the product was mined from
	 * @return
	 */
	std::string website() const { return m_sourceWebsite; }

	/**
	 * Just gets the product string representation for logging purposes
	 * @return
	 */
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
