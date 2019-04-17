/*
 * lab2.cpp
 *
 *  Created on: Feb 22, 2019
 *      Author: sejoy
 */
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;

void printthings();
void add4(int x);
int rand50();
void cube(int *x);
void rand10(int x);
void change(int *x, int *y);
void calls(char one, char *two, char &three);
bool swap(int *x, int *y);
void rand25();
void randarray(int length, int &y);
void randarray2(int length);
void sortrandarray(int length, int range);
int *newvar();
void printarr(int arr[], int length);
void randnums(int *a, int *b, int *c);
void *randnums2(int x);
void printarraddress(int arr[], int size);
void printdoublearr(double arr[], int size);
void removeDoubles(int arr[], int *size);
int hanningWindow(int arr[], int size);
void filter(int arr1[], int size);
void graph(int* arr[], int size, int high, int low);
int** twoDarr(int *size1, int *size2);

int main(){
	srand(time(NULL));
	//Problem 1
	cout << "Problem 1:" << endl;
	printthings();
	//Problem 2
	//Call by value
	cout << "Problem 2:" << endl;
	int two = 100;
	cout << "value: " << two << endl;
	cout << "address: " << &two << endl;
	add4(two);
	cout << "value: " << two << endl;
	cout << "address: " << &two << endl;
	//Problem 3
	cout << "Problem 3:" << endl;
	int random50 = rand50();
	cout << "value: " << random50 << endl;
	cout << "address: " << &random50 << endl;
	//Problem 4
	//Call by pointer
	cout << "Problem 4:" << endl;
	int x = 2;
	cout << "value: " << x << endl;
	cout << "address: " << &x << endl;
	cube(&x);
	cout << "value: " << x << endl;
	cout << "address: " << &x << endl;
	//Problem 5
	//Call by value
	cout << "Problem 5:" << endl;
	int y = 2;
	cout << "value: " << y << endl;
	cout << "address: " << &y << endl;
	rand10(y);
	cout << "value: " << y << endl;
	cout << "address: " << &y << endl;
	//Problem 6
	cout << "Problem 6:" << endl;
	int ten = 10;
	int twenty = 20;
	change(&ten, &twenty);
	cout << "value: " << ten << endl;
	cout << "value: " << twenty << endl;
	//Problem 7
	cout << "Problem 7:" << endl;
	char d = 'd';
	char a = 'a';
	char t = 't';
	char e = 'e';
	char u = 'u';
	char c = 'c';
	cout << d << a << t << a << endl;
	calls(e,&d,a);
	cout << d << t << a << u << c << t << u << a << e << d << endl;
	//Problem 8a test
	cout << "Problem 8a:" << endl;
	int n = 2;
	int p = 1;
	cout << swap(&n, &p) << endl;
	//Problem 8b test
	cout << "Problem 8b:" << endl;
	rand25();
	//Problem 8
	cout << "Problem 8:" << endl;
	randarray(5, x);
	randarray(7, y);
	randarray(10, x);
	//Problem 9
	cout << "Problem 9:" << endl;
	randarray2(5);
	randarray2(7);
	randarray2(10);
	//Problem 10
	cout << "Problem 10:" << endl;
	sortrandarray(5, 5);
	sortrandarray(7, 50);
	sortrandarray(10, 100);
	//Problem 11
	//It compiled, but it gave me a correct value inside
	//the function and an incorrect one when printing from main.
	cout << "Problem 11:" << endl;
	int *b = newvar();
	cout << "value: " << b << endl;
	cout << "address: " << &b << endl;
	//Problem 12b
	int arr12[25];
	for(int i=0; i<=25; i++){
		arr12[i]=rand()%10+1;
	}
	//Problem 12
	cout << "Problem 12:" << endl;
	printarr(arr12, 25);
	//Problem 13
	cout << "Problem 13:" << endl;
	int z = 100;
	randnums(&x,&y,&z);
	/*Problem 14
	This shouldn't work because it creates an array on the
	stack inside the function, so the array vanishes once
	the function is finished.
	cout << "Problem 14:" << endl;
	int randomarray = randnums2(30);
	printarr(randomarray, 30);*/
	//Problem 15
	cout << "Problem 15:" << endl;
	int arr[5] = {1,2,3,4,5};
	printarraddress(arr, 5);
	//Problem 16
	cout << "Problem 16:" << endl;
	double arr2[5] = {1.2, 2.5, 3.4, 4.1, 5.2};
	printdoublearr(arr2, 5);
	//Problem 17
	cout << "Problem 17:" << endl;
	int ap = 10;
	int *size = &ap;
	int removeDoublesArray[10] = {1,1,1,2,3,4,4,5,6,5};
	removeDoubles(removeDoublesArray, size);
	//Problem 18
	cout << "Problem 18:" << endl;
	int arr18[10] = {12, 5, 1, 100, 8, 15, 35, 99, 2, 3};
	int average = hanningWindow(arr18, 10);
	cout << average << endl;
	cout << "Problem 19:" << endl;
	filter(arr18, 10);
	//Problem 20
	cout << "Problem 20:" << endl;
	//graph(arr18, 10, 100, 1);
	//Problem 21
	int** twodarray = new int *[3];
	for(int i=0; i<3; i++){
		twodarray[i] = new int[3];
	}
	printarr(*twodarray, 3);
}

//Problem 1
//input: none
//output: void
//prints the value and address of a locally defined variable
void printthings(){
	int x = 100;
	cout << "value: " << x << endl;
	cout << "address: " << &x << endl;
}

//Problem 2
//Call by value
//input: an integer
//output: adds 4 to that integer within the function
//and prints the new value and address
//does not permanently change the value of that variable
void add4(int x){
	x+=4;
	cout << "value: " << x << endl;
	cout << "address: " << &x << endl;
}

//Problem 3
//input: none
//output: an integer
//creates a variable with a random value between 0 and 50 and
//returns the value and address
int rand50(){
	int x = rand()%50;
	cout << "value: " << x << endl;
	cout << "address: " << &x << endl;
	return x;
}

//Problem 4
//Call by pointer
//input: address of an integer
//output: void
//cubes the input number and prints out its value, the
//address the variable holds, and the address of the variable
void cube(int *x){
	*x = pow(*x, 3.0);
	cout << "value: " << x << endl;
	cout << "address in parameter: " << *x << endl;
	cout << "address of parameter: " << &x << endl;
}

//Problem 5
//Call by value
//input: an integer
//output: void
//creates a random number between one and ten and adds
//it to the input value, prints out the random number
//the new value and the address of the parameter
void rand10(int x){
	int y = rand()%10;
	x += y;

	cout << "random number: " << y << endl;
	cout << "new value: " << x << endl;
	cout << "address: " << &x << endl;
}

//Problem 6
//input: two pointers
//output: void
//changes the values of the two inputs
void change(int *x, int *y){
	int *a = x;
	*a = 32;
	a = y;
	*a = 42;
}

//Problem 7
//input: three chars as call by value, pointer, reference
//output: void
//prints a fun phrase by changing the defined characters
//inside the function
void calls(char one, char *two, char &three){
	one = 'p';
	*two = 's';
	three = 'r';
}

//Problem 8a
//input: two pointers
//output: boolean
//swaps two values if the first is bigger than the second
bool swap(int *x, int *y){
	int tmp;
	bool swapped = false;
	if(*x>*y){
		tmp = *x;
		*x=*y;
		*y=tmp;
		swapped = true;
	}
	return swapped;
}

//Problem 8b
//input: none
//output: void
//generates 2 random numbers between 0 and 25 20 times,
//then prints them out. calls 8a. prints out the values
//each time it loops.
void rand25(){
	int x;
	int y;
	for(int i=0; i<=20; i++){
		x = rand()%25;
		y = rand()%25;
		cout << "x value: " << x << endl;
		cout << "y value: " << y << endl;
		bool isSwapped = swap(&x,&y);
		if(isSwapped==true){
			cout << "swapped x value: " << x << endl;
			cout << "swapped y value: " << y << endl;
		}
	}
}

//Problem 8
//input: an integer and a pass by reference int
//output: void
//creates an array of random length 1 to 50
//prints the array and the smallest value
void randarray(int length, int &y){
	y = -1;
	int arr[length];
	y = arr[0];
	for(int i=0; i<=length; i++){
		arr[i] = rand()%50;
		cout << arr[i] << " , ";
		if(arr[i]<y){
			y = arr[i];
		}
	} cout << endl;
	cout << "smallest value: " << y << endl;
}

//Problem 9
//input: integer
//output: void
//generates an array of random numbers the length of the input
//fills new array with random numbers 0 to 50, then prints the array
//then reverses the array and prints the reversed array
void randarray2(int length){
	int arr[length];
	int tmp=arr[0];
	for(int i=0; i<length; i++){
		arr[i] = rand()%50;
		cout << arr[i] << " , ";
	}cout << endl;
	//reverse array
	for(int j = 0; j < length/2; ++j){
	   tmp = arr[j];
	   arr[j] = arr[length-j-1];
	   arr[length-j-1] = tmp;
	}
	for(int k=0; k<length; k++){
		cout << arr[k] << " , ";
	}cout << endl;
}

//Problem 10
//input: two integers
//output: void
//prints an array in order by finding the smallest number
//and then replacing it with a number larger than the
//largest possible number
void sortrandarray(int length, int range){
	int arr[length];
	int smallest = arr[0];
	for(int i=0; i<length; i++){
		arr[i] = rand()%range;
		cout << arr[i] << ",";
	}cout << endl;
	for(int k=0; k<length; k++){
		for(int j=0; j<length; j++){
			if(arr[j]<smallest){
				smallest = arr[j];
			}
		}cout << arr[k] << ",";
	}cout << endl;
	cout << smallest << endl;
	smallest = range+1;
}

//Problem 11
//input: none
//output: an address
//creates a new variable and prints its value and address
//prints the value and address in main too, they are different
int *newvar(){
	int var = 3;
	cout << "value: " << var << endl;
	cout << "address: " << &var << endl;
	return &var;
}

//Problem 12
//input: array and integer
//output: void
//prints an array
void printarr(int arr[], int length){
	for(int i=0;i<length-1; i++){
		cout << arr[i] << ',';
	}cout<<arr[length-1]<<endl;
}

//Problem 13
//input: three pointers
//output: void
//creates an array on the heap with random numbers between
//a random high and low number, then prints the array
void randnums(int *a, int *b, int *c){
	int random = rand()%25 + 25;
	int *arr = new int[random];
	int high = rand()%5 + 5;
	int low = -(rand()%5 + 5);
	for(int i=0; i<random; i++){
		arr[i] = low + (rand()%(high-low));
	}
	*a = random;
	*b = high;
	*c = low;
	printarr(arr, random);
}

//Problem 14
//input: integer
//output: void
//creates an array and returns its first value - doesn't work
// because the array is a local variable and dissapears once
//the function is done running
void *randnums2(int x){
	int arr[x];
	int high = rand()%5 + 5;
	int low = -(rand()%5 + 5);
	for(int i=0; i<x; i++){
		arr[i] = low + (rand()%(high-low));
	}
	return &arr[0];
}

//Problem 15
//input: array and integer
//output: void
//prints all of the addresses of variables in an array
void printarraddress(int arr[], int size){
	for(int i=0; i<size; i++){
		cout << &arr[i] << ",";
	}cout << endl;
}

//Problem 16
//input: double array and integer
//output: void
//prints all of the addresses of a double array
void printdoublearr(double arr[], int size){
	for(int i=0; i<size; i++){
		cout << &arr[i] << ",";
	}cout << endl;
}

//Problem 17
//input: array, pointer
//output: void
//removes all the doubles in an array that occur next to
//each other and prints the new array
void removeDoubles(int arr[], int *size){
	int newSize = *size;
	int doubles = newSize;
	int *newarr = new int[newSize];
	newarr[0]=arr[0];
	int j=0;
	for(int i=0; i<newSize; i++){
		if(arr[i]!=arr[i+1]){
			newarr[j]=arr[i];
			j++;
			doubles--;
		}
	}
	newSize-=doubles;
	printarr(newarr, newSize);
}

//Problem 18
//input: array, integer
//output: integer
//returns the average of the values in an array which are
//multiplied by the hanning window instructions
int hanningWindow(int arr[], int size){
	int sum=0;
	int index = 0;
	for(int i=1; i<(size/2)+1; i++){
		sum+=arr[index]*i;
		index++;
	}
	for(int j=(size/2)+1; j>0; j--){
		sum+=arr[index]*j;
		index++;
	}
	int ave = sum/pow((size/2)+1,2);
	return ave;
}

//Problem 19
//input: array as pointer, integer
//output: void
//prints an array that has been filtered by the hanning window
void filter(int arr1[], int size){
	int *arr2= new int[size];
	*arr2 = hanningWindow(arr1, size);
	printarr(arr2, size);
	printarr(arr1, size);
}

//Problem 20
//input: array, three integers
//output: void
//prints a graph of the array in the console
void graph(int arr[], int size, int high, int low){
	for(int i=high; i>=low; i--){
		for(int j=0; j<size; j++){
			cout << high << ":";
				if(arr[j]==i){
					cout << "*";
				}
		}cout << endl;
	}
}

//Problem 21
//input: two pointers
//output: 2D array
//creates a 2D array and fills with random numbers
int** twoDarr(int *size1, int *size2){
	int x = rand()%5 + 5;
	int y = rand()%4 + 4;
	*size1 = x;
	*size2 = y;
	int** arr = NULL;
	arr = new int *[*size1];
	for(int i=0; i<*size1; i++){
		arr[i] = new int[*size2];
		for(int j=0; j<*size2; j++){
			arr[i][j] = 0;
		}
	}
}
