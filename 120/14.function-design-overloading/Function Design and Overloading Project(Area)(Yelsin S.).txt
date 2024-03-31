// This lab calculates the area for a circle, square, and triangle
// by calling functions from main to perform specific task. 
// Function Design and Overloading Project(Area)
// Developed by: Yelsin Sepulveda
// Last modified: July 31, 2017

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;

void printBanner();
char getYesOrNo(char x);
double area(double radius);
double area(double length, double width);
double area(double firstSide, double secondSide, double thirdSide);
double getPositiveDouble();
void getValidTriangle(double &firstSide, double &secondSide, double &thirdSide);

int main() {
	system("TITLE Function Design and Overloading Project(Area)			By Yelsin S.");
	system("COLOR 70");

	double inputOne, inputTwo, inputThree;
	char choice;

	printBanner();

	cout << "Do you want to test the program?" << setprecision(6) << fixed;
	cin >> choice;  cin.ignore(100, '\n');

	while (getYesOrNo(choice) == 'y' || getYesOrNo(choice) == 'Y') {

		cout << "\nGive me the radius of a circle : ";
		inputOne = getPositiveDouble();					// inputOne is variable for radius.

		cout << "\t\t The area of the circle is " << area(inputOne) << endl;

		cout << "\nGive me the length of a rectangle: ";
		inputOne = getPositiveDouble();					// inputOne is variable for length.

		cout << "...and the width: ";
		inputTwo = getPositiveDouble();					// inputOne is variable for width.

		cout << "\t\t The area of the rectangle is " << area(inputOne, inputTwo) << endl;

		cout << "\nGive me the length of the sides of a triangle. \n";
		cout << "Side 1: ";
		inputOne = getPositiveDouble();

		cout << "Side 2: ";
		inputTwo = getPositiveDouble();

		cout << "Side 3: ";
		inputThree = getPositiveDouble();

		getValidTriangle(inputOne, inputTwo, inputThree);

		system("COLOR 70");

		cout << "The area of the triangle is " << area(inputOne, inputTwo, inputThree) 
			<< endl << "\n\n\t ********************* \n" << "\nDo you want to test the program again? ";
		cin >> choice;  cin.ignore(100, '\n');
		resemble 
	}

	return 0;
}

void printBanner() {
	cout << endl
		<< "\t          Project on Designing Overloading Functions       \n"
		<< "\t       Find the area of a rectangle, triangle, or circle   \n"
		<< "\t             also does extensive input validation          \n"
		<< "\t               and uses by reference variables             \n"
		<< "\t                         by Yelsin S.                      \n"
		<< endl;
}

char getYesOrNo(char x) {
	char newChoice = x;

	while (!(newChoice == 'y' || newChoice == 'Y' || newChoice == 'n' || newChoice == 'N')) {
		cout << "Please type Y or N. Try again: ";
		cin >> newChoice; cin.ignore(100, '\n');
	}

	if (newChoice == 'n' || newChoice == 'N') {
		cout << "Don't you love Geometry? \n";

		system("PAUSE");
		exit(0);
	}

	return newChoice;
}

double getPositiveDouble() {
	double positiveDouble;
	cin >> positiveDouble;

	while (positiveDouble <= 0) {
		cout << "Positive numbers only please.Try again : ";
		cin >> positiveDouble;
	}

	return positiveDouble;
}

double area(double radius) {
	const double PI = 3.141592;

	return (PI *(pow(radius, 2)));
}

double area(double length, double width) {
	double area = length * width;

	return area;
}

double area(double firstSide, double secondSide, double thirdSide) {
	double perimeter;

	perimeter = (firstSide + secondSide + thirdSide) / 2;

	return sqrt(perimeter*((perimeter - firstSide) * (perimeter - secondSide) * (perimeter - thirdSide)));
}

void getValidTriangle(double &firstSide, double &secondSide, double &thirdSide) {
	while (firstSide + secondSide < thirdSide || secondSide + thirdSide < firstSide || firstSide + thirdSide < secondSide) {
		system("COLOR FC");
		cout << "The sum of two sides of a Triangle must be greater than the third side.\n"
			<< "try again: " << "Side 1 : ";
		firstSide = getPositiveDouble();

		cout << "Side 2: ";
		secondSide = getPositiveDouble();

		cout << "Side 3: ";
		thirdSide = getPositiveDouble();
	}
}