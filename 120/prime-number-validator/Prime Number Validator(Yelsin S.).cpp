// This lab uses main() to ask users to enter an INTERGER type number
// and calls my second function checkForPrime() to determine whether the number is a prime number.
// Prime Number Validator.
// Developer Yelsin Sepulveda
// Last modified: July 19

#include <iostream>
#include <string>
using namespace std;

bool checkForPrime(int x, int z);

int main() {
	system("COLOR 70");
	system("TITLE Prime Number Validator       by Yelsin S.");

	int userInput, nTimesDivided;

	cout << endl
		<< "\t\t      This lab ask users for an INTEGER and calculates     \n"
		<< "\t\t                 whether the number entered                \n"
		<< "\t\t                     is a prime number                     \n"
		<< "\t\t                        by Yelsin S.                       \n"
		<< endl;

	while (true) {
		cout << "\nEnter a whole number to determine wether it is a prime number: ";
		cin >> userInput; cin.ignore(100, '\n');

		nTimesDivided = 0;

		cout << endl
			<< "\t\t " << (checkForPrime(userInput, nTimesDivided) == true ? "True" : "False") << ". " << userInput
			<< ' ' << (checkForPrime(userInput, nTimesDivided) == true ? "is" : "is not") << " a prime number. \n";
		 
		system("PAUSE");
	}
}
bool checkForPrime(int x, int z) {
	for (int y = 2, c = 0; y <= x && c < 1; ++y, ++z)
		x % y == 0 ? ++c : c+= 0;   // as soon as you find a divisor rturn the answer

	return (z == (x-1));
}

