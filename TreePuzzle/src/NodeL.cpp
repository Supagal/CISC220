/*
 * NodeL.cpp
 *
 *  Created on: Apr 19, 2019
 *      Author: sejoy
 */

#include "NodeL.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

NodeL::NodeL(){
	word = "";
	next = NULL;
}
NodeL::NodeL(string w){
	word = w;
	next = NULL;
}
void NodeL::printNode(){
	cout << " " << endl;
}
NodeL::~NodeL(){}


