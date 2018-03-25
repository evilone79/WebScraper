/*
 * ProductDalDummy.h
 *
 *  Created on: Mar 24, 2018
 *      Author: deth
 */

#ifndef PRODUCTDALDUMMY_H_
#define PRODUCTDALDUMMY_H_

#include "ProductDal.h"
#include <mutex>

namespace dal
{

/**
 * Dummy implementation for Product DAL. Just prints out the Product being inserted
 */
class ProductDalDummy: public virtual ProductDal
{
public:
	ProductDalDummy();
	virtual ~ProductDalDummy();

	virtual void insert_product(Product const& product) override;

private:
	std::mutex m_mut;
};

} /* namespace dal */

#endif /* PRODUCTDALDUMMY_H_ */
