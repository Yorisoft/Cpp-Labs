// This lab takes TWO numbers and uses TWO fucntions and determines
// wether to add or to based on the signs of the numbers.
// Sum or Pruduct - Sign diffrence(Yelsin S.)
// Developed by: Yelsin Sepulveda
// Last modified

#include <iostream>
using namespace std;

double sumOrProd(double x, double y);

int main(){
	system("TITLE Sum or Pruduct - Sign Difference (Yelsin S.)");
	system("COLOR 70");

	double inputOne, inputTwo;

	cout << endl
		 << "\t\t   This lab takes TWO numbers and uses TWO fucntions     \n"
		 << "\t\t        and determines wether to add or to based         \n"
		 << "\t\t              on the signs of the numbers.               \n"
		 << endl;

	while (true){
		cout << endl << "\nWhat is the first number? ";
		cin >> inputOne; cin.ignore(100, '\n');

		cout << "\nWhat is the second number? ";
		cin >> inputTwo; cin.ignore(100, '\n');

		cout << "\nThe result of sumProd with arguments " << inputOne << " and " << inputTwo << " is " 
			<< sumOrProd(inputOne, inputTwo) << ". \n\n";

		cout << "Press Enter to continue";
		cin.ignore(100, '\n');
	}
	return 0;
}

double sumOrProd(double x, double y) {
	return  (x*y >= 0 ? x + y : x*y );
}