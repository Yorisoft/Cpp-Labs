// This Lab uses file stream object, ifstream in this case, to open and read data from a file and then returns the 
// mathematically correct average. 
// File Open Validation and Average(Yelsin S.)
// Created by Yelsin Sepulveda
// Last modified: July 17th, 2017

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	system("COLOR 70");
	system("TITLE File Open Validation and Average       by Yelsin S. ");

	ifstream inputFile;

	int firstInt, secondInt;

	string fileName;

	cout <<endl
		<< "\t     This program asks the user for the name of a file that     \n"
		<< "\t                    contains two numbers,                       \n"
		<< "\t            and prints on the monitor their averge              \n"
		<< "\t                         by Yelsin S.                           \n";

	while (true) {
		cout << endl << "What file contains your data? ";
		getline(ws(cin), fileName);

		// Open the file.
		inputFile.open(fileName);

		/* if (inputFile.fail()) {
			cout << "\n\n\nFailed to open file: \"" << fileName 
				<< "\". Please provide a different file name.. \n\n";

			system("PAUSE");
			return 0;
		} */

		// If ifstream fails to open.
		while (inputFile.fail() || fileName == "\n") { 
			system("COLOR C0");
			cout << "\n\n\nFailed to open file: \"" << fileName
				<< "\". Please provide a different file name: ";
			
			getline(ws(cin), fileName);
		}

		// Read two integers from the file.
		inputFile >> firstInt;
		inputFile >> secondInt;

		// Close file. ASAP.
		inputFile.close();

		// Print the mathematically correct average.
		cout << endl
			<< "The average of " << firstInt << " and " << secondInt << " is: " 
			<< setprecision(2) << (double)(firstInt + secondInt) / 2 << endl << endl;

		system("PAUSE");
		
		exit(0);
	}
	return 0;
}