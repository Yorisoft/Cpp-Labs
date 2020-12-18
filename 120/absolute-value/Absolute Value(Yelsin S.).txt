// This lab uses ask the user for a number and uses TWO function to calculate and display - 
// the absolute value of the users input.
// Quick Function For Absolute Value Of N
// Developed by: Yelsin Sepulveda
// Last modified: July 20, 2017.

#include <iostream>
using namespace std;

double absoluteValueOfN(double x);

int main(){
	system("COLOR 70");
	system("TITLE Quick Function For Absolute Value Of N by Yelsin S.");

	double userInput;

	cout << endl
		<< "\t\t  This lab uses ask the user for a number and uses     \n"
		<< "\t\t      TWO function to calculate and display the        \n"
		<< "\t\t          absolute value of the users input            \n"
		<< "\t\t                      Yelsin S.                        \n\n";

	while(true) {
		cout << "\nEnter a number to find out its absolute value: ";
		cin >> userInput; cin.ignore(100, '\n');

		cout << "\n\t\t\t" << "  The absolute value of " << userInput << " is "
			<< absoluteValueOfN(userInput) << ". \n\n";

		system("PAUSE");
	}
}
double absoluteValueOfN(double x) {
	return (x < 0 ? -1*x : x);
}