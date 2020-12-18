// In this lab exercise, you will write a program to demonstrate two concepts :
// 1. Using pointers as function parameters for arrays.
// 2. Dynamic memory allocation.
//
// Prof. Peter Morgan
// CSC237 Lab09: Pointers
// Yelsin Sepulveda
// November 20, 2020.

#include<iostream>
#include<string>
#include <sstream>
#include<iomanip>
using namespace std;

void popublateIntegerArray(int* arrayPtr, int arraySize);
void displayIntegerArray(int* arrayPtr, int arraySize);
void findMaximumInteger(int* arrayPtr, int arraySize);


int main() {
	int *arrayPtr, arraySize;

	while (true) {
		cout << "Enter desired array size: ";
		cin >> arraySize;

		arrayPtr = new int[arraySize];
		cout << "arrayPtr = " << arrayPtr << endl;

		popublateIntegerArray(arrayPtr, arraySize);
		displayIntegerArray(arrayPtr, arraySize);
		findMaximumInteger(arrayPtr, arraySize);

		cout << "DELETING array at arrayPtr = " << arrayPtr << endl;
		delete[] arrayPtr;

		system("pause");
	}
	return 0;
}

void popublateIntegerArray(int *arrayPtr, int arraySize){
	for (int y = 0; y < arraySize; y++) {
		cout << "Enter value for array element " << y << ": ";
		cin >> *(arrayPtr + y);
	}
}

void displayIntegerArray(int *arrayPtr, int arraySize) {
	stringstream ss;

	for (int y = 0; y < arraySize; y++) {
		cout << arrayPtr + y << ":\t"
			<< "arrayPtr[" << y << "] = \t\t"
			<< *(arrayPtr + y) << endl;

	//	ss << hex << *(arrayPtr + y);
	//	string hexString(ss.str());
	//	
	//	cout << hexString << endl;
	}
}

void findMaximumInteger(int* arrayPtr, int arraySize) {
	int largestInt;
	largestInt = *arrayPtr;

	for (int y = 1; y < arraySize; y++) {
		*(arrayPtr + y) > largestInt ? largestInt = *(arrayPtr + y) : largestInt;
	}

	cout << "Maximum integer in array is: " << largestInt << endl;
}