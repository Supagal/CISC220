/* Sarah Joyce
 * Professor Yarrington
 * CISC220: Data Structures
 * 3/21/19
 * main.cpp
 */
/************MAIN FUNCTION ********************/
#include <iostream>
#include <stdlib.h>
#include "SLL.hpp"
using namespace std;

int main(){
	int r[10] = {9,8,4,5,11,10,3,6,8,2};
	string s[10] = {"really good!","loved it","mediocre", "okay, not great","best book ever!", "awesome!","boring","not bad","definitely worth reading", "terrible!"};
	SLL *list = new SLL();
	for(int i = 0; i < 10; i++) {
		list->insertInOrder(r[i],s[i]);
		list->printSLL();
	}
	cout << "Ave: " << list->getAve() << endl;
	cout << list->pop() << endl;
	list->printSLL();
	cout << list->pop() << endl;
	list->printSLL();
	delete list;
	return 0;
}
SLL::SLL(){
	first = NULL;
	last = NULL;
	size = 1;
}
SLL::~SLL(){
	SNode *tmp = first;
	while(tmp!=NULL){
		cout<< "deleting " << tmp->rating << "," << tmp->comments << endl;
		tmp=tmp->next;
	}
	cout << "deleted each node in " << size << endl;
}
void SLL::printSLL(){
	SNode *tmp = first;
	while(tmp!=NULL){
		cout << "Rating: " << tmp->rating << "," << "Comments: " << tmp->comments << endl;
		tmp = tmp->next;
	}cout << endl;
}
void SLL::push(int r, string c){
	SNode *n = new SNode(r,c);
	last->next=n;
	last=n;
	size++;
}
void SLL::addAtFront(int r, string c){
	SNode *tmp = first;
	SNode *n = new SNode(r,c);
	first = n;
	n->next = tmp;
	size++;
}
void SLL::addFirst(int r, string c){
	size++;
	first = new SNode(r,c);
	last=first;
}
int SLL::pop(){
	SNode *tmp = first;
	while(tmp->next->next!=NULL){
		tmp=tmp->next;
	}
	int x = last->rating;
	delete last;
	last = tmp;
	last->next = NULL;
	//size--;
	cout << "Popping ";
	return x;
	cout << endl;
}
double SLL::getAve(){
	double sum=0;
	SNode *tmp = first;
	for(int i=0; i<10; i++){
		sum += tmp->rating;
		tmp=tmp->next;
	}
	double average = sum/10;
	return average;
}

void SLL::insertInOrder(int r, string c){
	if(first==NULL){
		addFirst(r,c);
	}else if(r<first->rating){
		addAtFront(r,c);
	}else if(r>last->rating){
		push(r,c);
	}else{
		SNode *tmp = first;
		while(tmp->rating<r-1){
			tmp = tmp->next;
		}SNode *tmp2 = tmp->next;
		tmp->next = new SNode(r,c);
		tmp->next->next = tmp2;
		size++;
	}
}
