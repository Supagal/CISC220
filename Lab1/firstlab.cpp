/* Sarah Joyce, Katarina Pfeifer
 * TA: Lauren Olson
 * Lab 2/15/19, due 2/21/19
 * Lab 1
 *
 * Created on: Feb 14, 2019
 *
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

//Problem 2
void stars();
//Problem 3
string isPrime(int n);
//Problem 4
int sum300();
//Problem 5
int bigSum();
//Problem 6
void mult(int x);
//Problem 7
void multTwo();
//Problem 8
void collatz();
//Problem 9
void leapYear();
//Problem 10
void starx(int num);
//Problem 11
void collatzTwo(int x, int y);

int main(){
	//Problem 1
	cout << "Problem 1: " << endl;
	cout << "!!!Hello, world!!!" << endl;
	stars();
	cout << "Problem 3: " << endl;
	cout << isPrime(5) << endl;
	cout << isPrime(15) << endl;
	cout << isPrime(541) << endl;
	stars();
	cout << "Problem 4: " << endl;
	cout<< sum300() << endl;
	stars();
	cout << "Problem 5: " << endl;
	cout << "The number of terms required to exceed 100000 is: " << bigSum() << endl;
	stars();
	cout << "Problem 7: " << endl;
	multTwo();
	stars();
	cout << "Problem 8: " << endl;
	collatz();
	stars();
	cout << "Problem 9: " << endl;
	leapYear();
	stars();
	cout << "Problem 10: " << endl;
	starx(5);
	starx(7);
	starx(9);
	stars();
	cout << "Problem 11: " << endl;
	collatzTwo(1,5);
	collatzTwo(3,7);
	collatzTwo(9,15);
	return 0;
}

//Problem 2
/* input: none
 * output: string: row of stars
 * function used to separate the outputs in the console
 */
void stars(){
	cout << "***********************************************************************************" << endl;
}

//Problem 3
/* input: integer
 * output: boolean (as a string)
 * function: determines whether a number is prime or not
 */
string isPrime(int n){
	string prime = "True";
	int x = 2;
	while(x<n-1){
		if(n%x==0){
			prime = "False";
			break;
		}
		x++;
	}
	return prime;
}

//Problem 4
/* input: none
 * output: multiple integers printed on separate rows
 * function prints the sum of the numbers every 20 numbers until 300
 */
int sum300(){
	int sum=0;
		for (int i=1; i<=300; i++) {
			sum+=i;
			if (i%20==0) {
				cout << "Current sum is: " << sum << endl;
			}
		}
		return sum;
}

//Problem 5
/* input: none
 * output: an integer
 * function: determines the number of terms needed to reach a sum of 100,000
 */
int bigSum(){
	int x = 0;
	int n = 0;
	while(n<=100000){
		x++;
		n = n+x;
	}
	return x;
}

//Problem 6
/* input: an integer
 * output: rows of strings
 * function: takes a number and prints out the 1-12 multiplication tables
 * for that number
 */
void mult(int x){
	for(int i=1; i<=12; i++){
		cout << x << " x " << i << " = " << x*i << endl;
	}
}

//Problem 7
/* input: none
 * output: rows of strings
 * function: prints all of the multiplication tables for 1-12
 */
void multTwo(){
	for(int i=1; i<=12; i++){
		mult(i);
	}
}

//Problem 8
/* input: none
 * output: prints an integer to the console
 * function: asks the user to enter a number and prints the number
 * of steps it takes to get to 1 by the Collatz Conjecture
 */
void collatz(){
	int n;
	int x = 0;
	cout << "Input a positive natural number: " << endl;
	cin >> n;
	while(n!=1){
		if(n%2==0){
			n = n/2;
			x++;
		}else{
			n = (n*3) + 1;
			x++;
		}
	}
	cout << x << endl;
}

//Problem 9:
/* Input = none
 * Output = none, prints to console
 * Purpose = to print what years are leap years from 2017-2417
 */
void leapYear(){
	int year = 2017;
	for(int i=0; i<400; i++){
		if((year%4==0)&&(year%100!=0)){
			cout << year << endl;
		}
		year++;
	}
}

//Problem 10
/* Input = Input, tells how big to make the x shape
 * Output = None, prints to console
 * Purpose = to create an x out of asterisks that corresponds to the size given
 */
void starx(int num) {
	if (num%2==0) {
		num=num+1;
	}
	for (int row = num; row>1; row--) {
		for (int spaces = 0; spaces <=(num-row); spaces++){
			cout<<" ";
		}
		cout<<"*";
		for (int spaces = (row*2)-3; spaces>=1; spaces--) {
			cout<<" ";
		}
		cout<<"*";
		for (int spaces = 0; spaces <=(num-row); spaces++){
			cout<<" ";
		}
		cout<<endl;
	}
	for (int spaces = 0; spaces <= (num-1); spaces++) {
		cout<<" ";
	}
	cout<<"*";
	for (int spaces = 0; spaces <= (num-1); spaces++) {
			cout<<" ";
	}
	cout<<endl;
	for (int row=2; row<=num; row++) {
		for (int spaces = num-row; spaces>=0; spaces--) {
			cout<<" ";
		}
		cout<<"*";
		for (int spaces = (row*2)-3; spaces>=1; spaces--) {
			cout<<" ";
		}
		cout<<"*";
		for (int spaces = num-row; spaces >=0; spaces--) {
			cout<<" ";
		}
		cout<<endl;
	}
}

//Problem 11
/* input: two integers
 * output: prints rows single integers and strings to the console
 * function: calculates the Collatz Conjecture for every number
 * between the first and second number and prints a string saying
 * it is working
 */
void collatzTwo(int x, int y){
	int a = x;
	while(x<=y){
		cout << a << endl;
		while(x!=1){
			if(x%2==0){
				x = x/2;
			}else{
				x = (x*3) + 1;
			}
		}
		a++;
		x = a;
		cout << "Collatz Conjecture is still working." << endl;
	}
}
