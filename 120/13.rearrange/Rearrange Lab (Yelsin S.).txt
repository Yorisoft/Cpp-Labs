// This lab takes two integers from the user and uses two seperate
// function (besides main) to rearrange and swap the memory location of both values. 
// mySwap Function Lab(Yelsin S.)
// Developed by: Yelsin S.
// Last modified 7 27, 2017

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void mySwap(int &x, int &y);

void rearrange(int &x, int &y, int &z);

int main() {
	system("TITLE       Rearrange Function Lab     by Yelsin S.");
	system("COLOR 70");

	int inputOne, inputTwo, inputThree,
		a = 1, b = 2, c = 3;

	string fileName = "DataSet.txt";

	ifstream inputFile;

	cout << endl
		<< "\t\t     Lab on \"Driver testing the Rearrange function.\"     \n"
		<< "\t\t      Rearrange ANY number of sets of three numbers        \n"
		<< "\t\t        from a given input file \"Data Set.txt\"           \n"
		<< "\t\t                     by Yelsin S.				   		   \n";

	while (true) {
		cout << "\n\nThe test data set MUST be in a file called \"Data Set.txt\".\n\n";
	
		inputFile.open(fileName);

	/*while (inputFile.fail()) {									// while filestream fails to open file
			system("COLOR 17");
			cout << endl 
				<< "\t Failed to open the input file named \"Data Set.txt\" \n"
				<< "\t Make sure the file is located in the same directory as your exe \n"
				<< "\t and it is spelled correctly including spacing and the filename extension.\n"
				<< "\t Unable to open the file. What is the file name you want to open? ";
			getline(ws(cin), fileName);

			inputFile.open(fileName);

		}*/

		if (inputFile.fail()) {
			system("COLOR 17");
			cout << endl
				<< "\t Failed to open the input file named \"Data Set.txt\" \n"
				<< "\t Make sure the file is located in the same directory as your exe \n"
				<< "\t and it is spelled correctly including spacing and the filename extension.\n"
				<< "\t ****    I am exiting the program.    *** \n\n";

			system("PAUSE");
			return 0;
		}

		for (int x = 1; x <= 6; ++x) {
			inputFile >> inputOne;
			inputFile >> inputTwo;
			inputFile >> inputThree;

			cout << "Before the call: x = " << inputOne << " y = " << inputTwo << " z = " << inputThree;
			cout << endl << inputOne << inputTwo << inputThree;

			rearrange(inputOne, inputTwo, inputThree);

			cout << "\nAfter the call: x = " << inputOne << " y = " << inputTwo << " z = " << inputThree;
			cout << endl << inputOne << inputTwo << inputThree << "\n\n";
		}

		/*while (inputFile >> inputOne >> inputTwo >> inputThree) {
			cout << "Before the call: x = " << inputOne << " y = " << inputTwo << " z = " << inputThree;
			cout << endl << inputOne << inputTwo << inputThree;

			rearrange(inputOne, inputTwo, inputThree);

			cout << "\nAfter the call: x = " << inputOne << " y = " << inputTwo << " z = " << inputThree;
			cout << endl << inputOne << inputTwo << inputThree << "\n\n";
		}*/

		system("PAUSE");

		cout << "\n\n"
			<< "\t HARDWIRE testing (using a for loop and a table format)\n\n"
			<< "\t x       y       z \n"
			<< "\t ================= \n";

		for (int x = 0, y = 1; x < 6; ++x, ++y) {
			cout << "START:  " << inputOne << "       " << inputTwo << "       " << inputThree << endl;
			
			rearrange(inputOne, inputTwo, inputThree);

			cout << "END:    " << inputOne << "       " << inputTwo << "       " << inputThree << endl << endl;

			switch(y) {
				case 1: swap(inputTwo, inputThree); break;
				case 2: swap(inputOne, inputTwo); break;
				case 3: swap(inputOne, inputTwo); swap(inputTwo, inputThree); break;
				case 4: swap(inputTwo, inputThree); swap(inputOne, inputTwo); break;
				case 5: swap(inputTwo, inputThree); swap(inputOne, inputTwo); swap(inputTwo, inputThree); break;
			}
		}

		system("PAUSE");
		return 0;
	}

	return 0;
}

void mySwap(int &x, int &y) {
	int tempContainer = x;
	x = y;
	y = tempContainer;
}

void rearrange(int &x, int &y, int &z) {
	if (x > y)
		mySwap(x, y);
	if (y > z)
		mySwap(y, z);
	if (x > y)
		mySwap(x, y);
}