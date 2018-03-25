/*
 * UrlDescriptor.h
 *
 *  Created on: Mar 22, 2018
 *      Author: deth
 */

#ifndef URLDESCRIPTOR_H_
#define URLDESCRIPTOR_H_

#include <string>

/**
 * Source URL data descriptor
 */
struct UrlDescriptor
{
	std::string hostname; // web site hostname
	std::string path;     // path to resource
};


#endif /* URLDESCRIPTOR_H_ */
