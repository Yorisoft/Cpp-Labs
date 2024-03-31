// This lab takes two integers from the user and uses a seperate
// function (besides main) to swap the memory location of both values. 
// mySwap Function Lab(Yelsin S.)
// Developed by: Yelsin S.
// Last modified 7 26, 2017

#include <iostream>
using namespace std;

void mySwap(int &x, int &y);

int main() {
	system("TITLE       mySwap Function Lab     by Yelsin S.");
	system("COLOR 70");

	int inputOne, inputTwo;

	cout << endl
		<< "\t\t     mySwap  Function     \n"
		<< "\t\t      and driver Lab      \n"
		<< "\t\t       by  Yelsin S.      \n";

	while (true) {
		cout << "\n\nEnter a number for x: ";
		cin >> inputOne; cin.ignore(100, '\n');

		cout  << "Enter a number for y: ";
		cin >> inputTwo; cin.ignore(100, '\n');

		cout << endl << "BEFORE the function call: " << "x = " << inputOne << " y = " << inputTwo;

		cout << endl << "\t I am calling the \"mySwap\" function ... \n";
		mySwap(inputOne, inputTwo);

		cout << "AFTER the function call:  x = " << inputOne << " y = " << inputTwo << "\n\n";

		cout << endl << "NOTE: The debugging couts are in the main. The actual swaping is happenind in the function.\n\n\n";

		system("PAUSE");
	}

	return 0;
}

void mySwap(int &x, int &y) {
	int tempContainer = x;
	x = y;
	y = tempContainer;
}