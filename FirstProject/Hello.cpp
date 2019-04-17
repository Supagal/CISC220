/*
 * Hello.cpp
 *
 *  Created on: Feb 12, 2019
 *      Author: sejoy
 */

#include <iostream>
#include <stdlib.h>
using namespace std;
//line comment
/*block comment*/

int addfunc(int x, int y);

int main(){
	cout << "!!!Hello, world!!!" << endl;
	int z = addfunc(3,4);
	return 0;
}
int addfunc(int x, int y){
	return (x+y);
}


