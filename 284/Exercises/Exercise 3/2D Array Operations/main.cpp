// 2D Array Operations Exercise 3
// This program uses a two-dimensional array to perform several mathematical operations
// Prof Carmelito Moreno - CSC 284-H1
// Yelsin Sepulveda

#include<iostream>
#include<cmath>
#include<string>
#include "ArrayOperation.h"
using namespace std;

void printHeader();
void printOperations();

int main() {
	string choice = "Yes";
	int operation, row, col;
	ArrayOperation* arrayClassPointer = new ArrayOperation;
	(arrayClassPointer)->populateArray();

	printHeader();

	while (choice[0] == 'Y' || choice[0] == 'y') {
		printOperations();

		cout << "What operation would you like to perform? [1 - 6] ";
		cin >> operation; cin.ignore(100, '\n');

		switch (operation) {
		case 1: cout << (arrayClassPointer)->getTotal();
			break;
		case 2: cout << (arrayClassPointer)->getAverage();
			break;
		case 3: cout << "What row would you like to perform this operation on ? ";
			cin >> row; cin.ignore(100, '\n');
			cout << (arrayClassPointer)->getRowTotal(row);
			break;
		case 4: cout << "What column would you like to perform this operation on ? ";
			cin >> col; cin.ignore(100, '\n');
			cout << (arrayClassPointer)->getColumnTotal(col);
			break;
		case 5: cout << "What row would you like to perform this operation on ? ";
			cin >> row; cin.ignore(100, '\n');
			cout << (arrayClassPointer)->getHighestInRow(row);
			break; 
		case 6: cout << "What row would you like to perform this operation on ? ";
			cin >> row; cin.ignore(100, '\n');
			cout << (arrayClassPointer)->getLowestInRow(row);
			break;
		default: cout << operation << " Is not a valid option. Please choose options 1 - 6";
		}

		cout << endl << "Would you like to perform another operation ? [Y/n] ";
		getline(cin, choice);
	}

	system("pause");
	return 0;
}

void printHeader() {
	cout << endl
		<< "     This program uses a 2D array to perform six different     " << endl
		<< "  mathematical operations using the values stored in the array " << endl;
}

void printOperations() {
	cout << endl << "Possible operations: " << endl
		<< "\t 1 - getTotal" << endl
		<< "\t 2 - getAverage" << endl
		<< "\t 3 - getRowTotal" << endl
		<< "\t 4 - getColumnTotal" << endl
		<< "\t 5 - getHighestInRow" << endl
		<< "\t 6 - getLowestInRow" << endl;
}