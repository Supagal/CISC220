#include "BSTY.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

BSTY::BSTY() {
	root = NULL;
}

//testing
int main(){
	BSTY* tree = new BSTY;
	tree->insertit("computer");
	tree->insertit("science");
	tree->insertit("byte");
	tree->insertit("pointer");
	tree->insertit("tree");
	tree->find("computer");
	tree->find("science");
	tree->find("byte");
	tree->find("pointer");
	tree->find("tree");
	delete tree;
	return 0;
}

bool BSTY::insertit(string x) {
	NodeT *tmp = root;
	NodeT *n = new NodeT(x);
	if(root==NULL){
		root = n;
		adjustHeights(n);
		return true;
	}else{
		while(tmp!=NULL){
			if (x<tmp->data){
				if(tmp->left==NULL){
					tmp->left = n;
					n->parent = tmp;
					adjustHeights(n);
					return true;
				}else{
					tmp=tmp->left;
				}
			}else if(x>tmp->data){
				if(tmp->right==NULL){
					tmp->right = n;
					n->parent = tmp;
					adjustHeights(n);
					return true;
				}else{
					tmp=tmp->right;
				}
			}else{
				break;
			}
		}return false;
	}
}

NodeT *BSTY::find(string x) {
	NodeT *tmp = root;
		if(root==NULL){
			cout << "x cannot be found" << endl;
			return NULL;
		}else{
			while((tmp->left!=NULL)||(tmp->right!=NULL)){
				if(x==tmp->data){
					tmp->printNode();
					return tmp;
				}
				if(x>tmp->data){
					tmp = tmp->right;
				}
				if(x<tmp->data){
					tmp = tmp->left;
				}
			}
			if(x==tmp->data){
				tmp->printNode();
				return tmp;
			}else{
				cout << "x cannot be found" << endl;
				return NULL;
			}
		}
}

void BSTY::adjustHeights(NodeT *n) {
	NodeT *tmp = n;
	while(tmp!=NULL){
		if((tmp->left==NULL)&&(tmp->right==NULL)){
			tmp->height = 1;
		}else if((tmp->left==NULL)&&(tmp->right!=NULL)){
			tmp->height = tmp->right->height + 1;
		}else if((tmp->right==NULL)&&(tmp->left!=NULL)){
			tmp->height = tmp->left->height + 1;
		}else if(tmp->left->height > tmp->right->height){
			tmp->height = tmp->left->height + 1;
		}else if(tmp->right->height > tmp->left->height){
			tmp->height = tmp->right->height + 1;
		}else{
			break;
		}
		tmp = tmp->parent;
	}
}

/*int BSTY::findBalance(NodeT *n){
	NodeT *tmp = n;
	int left = 0;
	int right = 0;
	int balance = 0;
	while(tmp->left!=NULL){
		left++;
		tmp=tmp->left;
	}tmp = n;
	while(tmp->right!=NULL){
		right++;
		tmp=tmp->right;
	}
	balance = right - left;
	return balance;
}*/

void BSTY::printTreeIO() {
	if (root == NULL) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreeIO(root);
	}
}

// Print the tree in order (left child, then parent, then right child).
// Use the slides, but make sure you can understand how the tree is 
// traversed in order
void BSTY::printTreeIO(NodeT *n) { }

void BSTY::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreePre(root);
	}
}

// Prints the tree using pre-order traversal (parent, then left child, then right
// child.  Use the slides, but make sure you understand how a tree is traversed in
// pre-order
void BSTY::printTreePre(NodeT *n) { }

void BSTY::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreePost(root);
		cout << endl;
	}
}

// Prints the tree using pre-order traversal (left child, then right, then parent)
// Use the slides, but make sure you understand how a tree is traversed in
// post-order
void BSTY::printTreePost(NodeT *n) { }

void BSTY::myPrint() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		myPrint(root);
		cout << endl;
	}
}
void BSTY::myPrint(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		myPrint(n->left);
		cout << n->data.length()-1;
		if (mine) {
			cout <<".";
			mine = false;
		}
		myPrint(n->right);
	}
}

/*NodeT *rotateRight(NodeT *n){
	NodeT *x = n->left;
	NodeT *tmp = x->right;

	//Perform rotation
	x->right = n;
	n->left = tmp;

	//update heights
	if(n->left->height > n->right->height){
		n->height = n->left->height+1;
	}else{
		n->height = n->right->height+1;
	}
	if(x->left->height > x->right->height){
		x->height = x->left->height+1;
	}else{
		x->height = x->right->height+1;
	}return x;
}

NodeT *rotateLeft(NodeT *n){
	NodeT *x = n->right;
	NodeT *tmp = x->left;

		//Perform rotation
		x->left = n;
		n->right = tmp;

		//update heights
		if(n->left->height > n->right->height){
			n->height = n->left->height+1;
		}else{
			n->height = n->right->height+1;
		}
		if(x->left->height > x->right->height){
			x->height = x->left->height+1;
		}else{
			x->height = x->right->height+1;
		}return x;
}*/

/*************************************************************************************/
/* Extra Credit Methods                                                              *
* Challenging: worth 35 EC pts to go towards labs                                   *
* NOTE: IF YOU CHOOSE NOT TO IMPLEMENT THESE METHODS, YOU ARE STILL RESPONSIBLE FOR *
* UNDERSTANDING HOW THEY WORK!!                                                     *
************************************************************************************
* When removing a node from a binary search tree, the resulting tree MUST BE a binary
* search tree.
*
* When removing a node, there are 3 conditions:
* 1: when the node being removed has no children, in which case the node is deleted,
* the node's parent is set to NULL, and the node's parent's height is adjusted (if
* necessary) and heights on up are adjusted.
* 2: when the node being removed has one child, in which case the node's parent points
* to the node's child, and the node's child points to the node's parent, and the node
* is deleted (and the height of the parent on up as necessary is adjusted)
* 3: when the node has 2 children, in which case the left-most child of the node's
* right child replaces the node.
* A couple of notes about this one: you are replacing a node with a node that is lower
* down in the tree.  That means that you are, in essence, removing the node from that
* lower position and moving it up to the old node's location.  Thus the replacing node
* must be removed using 1 or 2 above (why not 3?).  The heights must be adjusted after
* the replacing node is removed from its old location but before it is inserted into its
* new location.  Equally, the replacing node's height must be adjusted to be the larger of
* its two children's heights before you adjust heights above that.
*****************************************************************************************
* remove(): takes as input a string, uses the find method to find the node in the tree that
* holds that string, and then calls replace1, replace2, or replace3 depending on what type
* of replacing should be done.  It adjusts the heights, deletes teh node, and returns
* true if the removal was successful.
*/
bool BSTY::remove(string s) {
	return true;
}

/* remove1(): called when the node to be removed has no children. Takes as input the 
* node to be removed, and sets the parent of the node to point to NULL.
* helpful hint: if (n->parent->left == n) is true, then n is its parent's left child.
* Make sure you check to whether n is the root or not.
*/
void BSTY::remove1(NodeT *n) {

}

/* remove2(): called when the node to be removed has 1 child only.  Takes as input
* the node to be removed and bypasses it by making the parent point to the node's
* one child, and makes the node's one child point to the node's parent.
* This one needs a bunch of checking - you need to see if the node is the parent's
* left or right child, and you need to see if the node's child is its left or its
* right child.
* Also, make sure you check that if the node to be removed is the root, then the
* one child becomes the root.
*/ 
void BSTY::remove2(NodeT *n) {

}

/* remove3(): called when the node to be removed has 2 children.  Takes as input the
* node to be removed.  The node to replace the node to be removed should be the
* left-most descendent of the node's right child.  That way the binary search tree
* properties are guaranteed to be maintained.
* When replacing the node to be removed with the replacing node, the replacing node
* is, in essence, being removed from its place in the tree, and thus replace1 or
* replace2 methods should be used.
* The new node's parent must be set to the removed node's parent, the removed node's
* parent must point to the new node, the new node's left child must point to the
* removed node's left child (and the child must point to the new node as a parent),
* and the same for teh right child.
* Remember to take into account that the node being removed might be the root.
*/
void BSTY::remove3(NodeT *n) {

}

/* findMin(): takes as input a node, and finds the left-most descendant of its 
* right child.  The left-most descendent is returned.
*/
/*NodeT *BSTY::findMin(NodeT *n) {

}*/

void BSTY::myPrintEC() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		myPrintEC(root);
		cout << endl;
	}
}
void BSTY::myPrintEC(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		myPrintEC(n->left);
		cout << alpha[n->data.length()-2];
		myPrintEC(n->right);
	}
}


/************************************************************************/

