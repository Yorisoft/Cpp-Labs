// This lab asks users for their name and outputs it to the monitor by using the ws string manipulator, 
// which ignores all whitespaces in the beginning of a string up untill the first none-whitespace character.
// The Greeting Lab - Read My Full Name Using String.
// Developer: Yelsin Sepulveda.
// Last modified: 06/21/2017

#include <iostream>
#include <string>
using namespace std;

int main() {
	system("title  The Greeting Lab - Read My Full Name   by Yelsin S.");
	system("color 70");

	string name;

	 
	// banner
	cout << endl
		<< "                  The Greeting Lab                  " << endl
		<< "           Read My Full Name Using Strings          " << endl
		<< "                 by Yelsin Sepulveda                " << endl
		<< "                       Lab #2                       " << endl << endl << endl;

	while (true) {
		cout << "What is your FULL name? ";
		cin >> ws; getline(cin, name);

		cout << "Hello \"" << name << "\". \n \n";

		system("pause");
	}
	return 0;
}