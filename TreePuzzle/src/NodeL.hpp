/*
 * NodeL.hpp
 *
 *  Created on: Apr 19, 2019
 *      Author: sejoy
 */

#ifndef NODEL_HPP_
#define NODEL_HPP_

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class NodeL {
	friend class LL;
public:
	string word;
	NodeL *next;
	NodeL();
	NodeL(string w);
	~NodeL();
	void printNode();
};

#endif /* NODEL_HPP_ */
