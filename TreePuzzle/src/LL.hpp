/*
 * LL.hpp
 *
 *  Created on: Apr 19, 2019
 *      Author: sejoy
 */

#ifndef LL_HPP_
#define LL_HPP_

#include <iostream>
#include <string>
#include <stdlib.h>
#include "NodeL.hpp"
using namespace std;

class LL{
public:
	NodeL *first;
	NodeL *last;
	int size;
	int score;
	LL();
	void push(string s);
	void addFirst(string s);
	void printList();
	void getScore();
};

#endif /* LL_HPP_ */
