// This lab uses switch case and for loops to print out the multiplication table
// up to the user defined limit.
// Print THe Multuplication Table
// Yelsin Sepulveda
// July 13

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	system("title  Print The Multiplication Table Up To A User Defined Limit by Yelsin S.");
	system("color 70");

	const char
		ASCII_CHARACTER = 178;

	int definedLimit;

// Banner
	cout << endl
		<< "\t           Print the Multiplication Table               \n"
		<< "\t             up to a user defined limit                 \n"
		<< "\t                   By Yelsin S.                         \n\n";

	while (true) {
		cout << "Up to what number do you want to print the multiplication table? ";
		cin >> definedLimit; cin.ignore(100, '\n');

		while (definedLimit <= 0 || definedLimit > 12) {
			if (definedLimit <= 0) {
				cout << "\tYour number must be greater than or equal to 1.\n"
					<< "\tTry again: ";
				cin >> definedLimit; cin.ignore(100, '\n');
			}
			if (definedLimit > 12) {
				cout << "\tYour number must be less than or equal to 12.\n"
					<< "\tTry again: ";
				cin >> definedLimit; cin.ignore(100, '\n');
			}
		}

		cout << "      ";
		for (int counter = 1; counter <= definedLimit; counter++) {
			cout << setw(6) << counter;
		}

		cout << endl << "     ";
		for (int counter = 0; counter <= definedLimit * 6; counter++) {
			cout << ASCII_CHARACTER;
		}
		
		for (int counter = 1; counter <= definedLimit; counter++) {
			cout << endl << "   " << setw(2) << right << counter << ASCII_CHARACTER;
			for (int multiple = 1; multiple <= definedLimit; multiple++) {
				cout << setw(6) << right << counter * multiple;
			}
			
		}

		cout << "\n\nDont you love math! So lets do it again! \n\n";
		system("pause");
	}


	return 0;
}