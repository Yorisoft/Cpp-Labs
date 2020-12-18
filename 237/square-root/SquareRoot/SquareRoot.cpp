//	Design the Square Root Program
//	Prof.Peter Morgan CSC 237
//	Yelsin S.
//	Sep.26.2020

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main() {
	double inputNumber,	// we will calculate the square root of this number
		tolerance,	// the acceptable error for the approximation.
		difference,	// difference between estimate and quotient.
		quotient,	// inputNumber / estimate
		estimate;	// used as a “guess” of the square root result

	string answr = "y"; 
	cout << fixed << setprecision(18);

	while (answr == "yes" || answr == "y"){
		cout << "Enter a floating point number: ";
		cin >> inputNumber;

		cout << "Enter a desired tolarence value: ";
		cin >> tolerance;

		cout << "\ttolerance is: " << tolerance << "\n\n\n";
		
		cout << "Estimating square root of " << inputNumber << endl << endl;

		cout << 'n' << "\t\t"
			<< "estimate" << "\t\t"
			<< "quotient" << "\t\t\t"
			<< "difference" << "\t\t\n"
			<< "__" << "\t\t"
			<< "________" << "\t\t"
			<< "________" << "\t\t\t"
			<< "__________" << "\t\t\n\n";

		estimate = inputNumber / 2.0;
		int n = 1;	// loop counter
		do {

			quotient = inputNumber / estimate;
			difference = fabs(estimate - quotient);

			cout << n << "\t"
				<< estimate << "\t"
				<< quotient << "\t\t"
				<< difference << "\n";

			n++;
			estimate = (estimate + quotient) / 2.0;
		} while (tolerance < difference);

		cout << endl << "The square root of " << inputNumber << " is " << estimate
			<< "  (+ / - " << tolerance << " ) " << endl;

		cout << "Keep running ? Enter \"y\"  for \"yes\": ";
		cin >> answr;
	}
	cout << "Exiting program...";
}