/*
 * LL.cpp
 *
 *  Created on: Apr 19, 2019
 *      Author: sejoy
 */

#include "LL.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

LL::LL(){
	first = NULL;
	last = NULL;
	size = 1;
	score = 0;
}
void LL::push(string s){
	NodeL *n = new NodeL(s);
	last->next=n;
	last=n;
	size++;
}
void LL::addFirst(string s){
	size++;
	first = new NodeL(s);
	last=first;
}
void LL::printList(){
	NodeL *tmp = first;
	while(tmp!=NULL){
		cout << " " << endl;
		tmp = tmp->next;
	}cout << endl;
}

//need to finish
void LL::getScore(){
	NodeL *tmp = first;
	int s = 0;
	while(tmp!=NULL){
		s+= 0;
		tmp=tmp->next;
	}
	score = s;
}



