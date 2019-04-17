/*
 * SNode.cpp
 *
 *  Created on: Mar 20, 2019
 *      Author: sejoy
 */
#include "SNode.hpp"
#include <iostream>
using namespace std;

SNode::SNode(){
	rating = 0;
	comments = "";
	cout << "Input a rating: " << endl;
	cin >> rating;
	cout << "Input comments: " << endl;
	cin >> comments;
	next = NULL;
}
SNode::SNode(int r, string c){
	rating = r;
	comments = c;
	next = NULL;
}
void SNode::printNode(){
	cout << "Rating: " << rating << ", " << endl;
	cout << "Comments: " << comments << endl;
}
SNode::~SNode(){
	cout << "removing: " << rating << "," << comments << endl;
	cout << "deleting: " << rating << "," << comments << endl;
}


