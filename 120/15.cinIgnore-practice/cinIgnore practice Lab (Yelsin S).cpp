// This lab uses cin.ignore to ignore the first 9 characters (by typecasting \n into an int)
// or to stop at 'A' (by typecasting the number 65 to a char)
// CinIgnore practice Lab (Yelsin S)
// Developed by: Yelsin Sepulveda
// Last modified: July 7th, 2017.

#include <iostream>
using namespace std;

int main() {
	system("COLOR 70");
	system("TITLE			CinIgnore practice Lab		by (Yelsin S)");

	char randomeChar;

	while (true) {
		cout << "Type a string and then  a char: (I will use \"cin.ignore('\\n', 65):\" ";
		cin.ignore('\n', 65); cin >> randomeChar;

		cout << endl << "In ch I got: " << "\'" << randomeChar << "\'" << endl;

		system("PAUSE");
	}

}