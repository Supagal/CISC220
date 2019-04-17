/*
 * SLL.hpp
 *
 *  Created on: Mar 20, 2019
 *      Author: sejoy
 */

#ifndef SLL_HPP_
#define SLL_HPP_

#include "SNode.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

class SLL {
	SNode *first;
	SNode *last;
	int size;
public:
	SLL();
	~SLL();
	void printSLL();
	void push(int r, string c);
	void addAtFront(int r, string c);
	void addFirst(int r, string c);
	int pop();
	double getAve();
	void insertInOrder(int r, string c);
};



#endif /* SLL_HPP_ */
