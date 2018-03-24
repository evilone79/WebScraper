/*
 * ProductDalDummy.cpp
 *
 *  Created on: Mar 24, 2018
 *      Author: deth
 */

#include "ProductDalDummy.h"
#include <iostream>

namespace dal
{

ProductDalDummy::ProductDalDummy()
{
}

ProductDalDummy::~ProductDalDummy()
{
}

void ProductDalDummy::insert_product(const Product& product)
{
	std::lock_guard<std::mutex> lock(m_mut);
	std:: cout << "Inserting to dummy DB:\n" << product.debug_print();
}

} /* namespace dal */
