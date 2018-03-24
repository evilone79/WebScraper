/*
 * ProductDal.h
 *
 *  Created on: Mar 24, 2018
 *      Author: deth
 */

#ifndef PRODUCTDAL_H_
#define PRODUCTDAL_H_

#include "../contracts/Product.h"

namespace dal
{
class ProductDal
{
public:
	virtual ~ProductDal() {}
	virtual void insert_product(Product const& product) = 0;

	/*
	 * rest of the interface here:
	 *
	 * virtual std::vector<Product> find_products(std::string const& name) = 0;
	 * virtual void delete_product(Product const& product) = 0;
	 *
	*/

};

}
#endif /* PRODUCTDAL_H_ */
