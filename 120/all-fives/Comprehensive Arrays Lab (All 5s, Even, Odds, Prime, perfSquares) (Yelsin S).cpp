// This lab uses various functions and arrays to print out several number	, both to the console and a file. 
// Comprehensive Arrays Lab (All 5s, Even, Odds, Prime, perfSquares)
// Developed by: Yelsin Sepulveda
// Last modified: August 14, 2017

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// prototypes done
void printBanner(ostream &outputStream = cout);  
void loadArraysOf5s(int arrayOf5s[], int totalElements);
void loadOddArray(int oddArray[], int totalElements);
void loadEvenArray(int evenArray[], int totalElements);
void loadPSA(int psaArray[], int totalElements);
void loadPrimeNumberArray(int primeNumberArray[], int totalElements);
bool isPrime(int num);
void printArray(int currentArray[], int totalElements, int perLine = 5, ostream &outputStream = cout);   
char getYesOrNo(); 
void connectFileToStream(string & fileName, ofstream &outputStream);

int main() {
	const int
		FIVE_ARRAY_SIZE = 139,
		EVEN_ARRAY_SIZE = 90,
		ODD_ARRAY_SIZE = 100,
		PRIME_ARRAY_SIZE = 120,
		PSA_ARRAY_SIZE = 42;

	int
		arrayOf5s[FIVE_ARRAY_SIZE],
		oddArray[ODD_ARRAY_SIZE],
		evenArray[EVEN_ARRAY_SIZE],
		primeNumberArray[PRIME_ARRAY_SIZE],
		psaArray[PSA_ARRAY_SIZE];
	string fileName;
	char userChoice;
	ofstream fileOutput;

	system("TITLE Comprehensive Arrays Lab (All 5s, Even, Odds, Prime, perfSquares) By Yelsin S.");
	system("COLOR 70");

	printBanner();

// arrayOf5s section.
	cout << "Im oabout to call loadArraysOf5s ... \n";
	loadArraysOf5s(arrayOf5s, FIVE_ARRAY_SIZE);
	cout << "Finished loading arrayOf5s ... \n";

	cout << "I am about to call printArray (with the default value for the perLine)... \n";
	printArray(arrayOf5s, FIVE_ARRAY_SIZE);

	system("PAUSE");

// evenArray section.
	cout << endl << "I am about to call loadEvenArray ... \n";
	loadEvenArray(evenArray, EVEN_ARRAY_SIZE);
	cout << "Finish loading evenArray ... \n";
		
	cout << "I am about to call printArray (with 4 perLine)... \n";
	printArray(evenArray, EVEN_ARRAY_SIZE, 4);

	system("PAUSE");

// oddArray section.
	cout << endl << "I am about to call loadOddArray ... \n";
	loadOddArray(oddArray, ODD_ARRAY_SIZE);
	cout << "Finish loading oddArray ... \n";

	cout << "I am about to call printArray (with 3 perLine)... \n";
	printArray(oddArray, ODD_ARRAY_SIZE, 3);
		
	system("PAUSE");

// psaArray section.
	cout << endl << "I am about to call loadpsaArray ... \n";
	loadPSA(psaArray, PSA_ARRAY_SIZE);
	cout << "Finish loading psaArray ... \n";

	cout << "I am about to call printArray (with 1 perLine)... \n";
	printArray(psaArray, PSA_ARRAY_SIZE, 1);

	system("PAUSE");

// primeNumberArray section.
	cout << endl << "I am about to call loadPrimeNumberArray ... \n";
	loadPrimeNumberArray(primeNumberArray, PRIME_ARRAY_SIZE);
	cout << "Finish loading primeNumberArray ... \n";

	cout << "I am about to call printArray (with 2 perLine)... \n";
	printArray(primeNumberArray, PRIME_ARRAY_SIZE, 2);

	system("PAUSE");

	// fileStream Section.
	cout << endl << endl << "Do you want to the array to a file: ";
	userChoice = getYesOrNo();
	
	if (userChoice == 'Y' || userChoice == 'y') { 
		cout << endl << "What file do you want to output to the array? ";
		connectFileToStream(fileName, fileOutput);

		printBanner(fileOutput);

		// fileOutput arrayOf5s.
		fileOutput << "\nHere is the first " << FIVE_ARRAY_SIZE << " elements of the arrayOf5s two per line: \n";
		printArray(arrayOf5s, FIVE_ARRAY_SIZE, 2, fileOutput);

		// fileOutput evenArray.
		fileOutput << "\nHere is the first " << EVEN_ARRAY_SIZE << " elements of the evenArray two per line: \n";
		printArray(evenArray, EVEN_ARRAY_SIZE, 2, fileOutput);

		// fileOutput oddArray.
		fileOutput << "\nHere is the first " << ODD_ARRAY_SIZE << " elements of the oddArray three per line: \n";
		printArray(oddArray, ODD_ARRAY_SIZE, 3, fileOutput);

		// fileOutput psaArray.
		fileOutput << "\nHere is the first " << PSA_ARRAY_SIZE << " elements of the psaArray three per line: \n";
		printArray(psaArray, PSA_ARRAY_SIZE, 3, fileOutput);

		// fileOutput primeNumberArray.
		fileOutput << "\nHere is the first " << PRIME_ARRAY_SIZE << " elements of the primeNumberArray one per line: \n";
		printArray(primeNumberArray, PRIME_ARRAY_SIZE, 1, fileOutput);

		fileOutput.close();
	}

	system("PAUSE");
	return 0;
}

void printBanner(ostream &outputStream) {  //   done
	outputStream << endl
		<< "\t     This is a lab on completely filled arrays     \n"
		<< "\t                  By Yesin S.                      \n"
		<< endl;
}

void loadArraysOf5s(int arrayOf5s[], int totalElements) { // done
	for (int counter = 0; counter < totalElements; counter++)
		arrayOf5s[counter] = 5;
}

void loadEvenArray(int evenArray[], int totalElements) {   // done
	for (int counter = 0; counter < totalElements; counter++)  
		evenArray[counter] = (counter + 1) * 2;
}

void loadOddArray(int oddArray[], int totalElements) {// done
	for (int counter = 0; counter < totalElements; counter++)
		oddArray[counter] = (counter * 2) + 1;
}

void loadPSA(int psaArray[], int totalElements) {  // done
	for (int counter = 0; counter < totalElements;  counter++)
		psaArray[counter] = (counter + 1) * (counter + 1);
}

void loadPrimeNumberArray(int primeNumberArray[], int totalElements) {  // done
	for (int i = 0, start = 2; i < totalElements; i++) {
		while (!isPrime(start)) 
			start++;
		
		primeNumberArray[i] = start++;
	}
}

bool isPrime(int num) {   // done
	for (int i = 2; i < num; i++) 
		if (num % i == 0)
			return false;
	
	return true;
}

void printArray(int currentArray[], int totalElements, int perLine, ostream &outputStream) {  // done
	for (int counter = 1; counter <= totalElements; counter++)
		outputStream << currentArray[counter-1] << '\t' << (counter % perLine == 0 ? "\n" : "");
	outputStream << endl << endl;
}

char getYesOrNo() {  // done
	char userInput; 
	cin >> userInput; cin.ignore(100, '\n');

	while (!(userInput == 'Y' || userInput == 'y' || userInput == 'N' || userInput == 'n')) {
		cout << "Please type Y or N. Try again: ";
		cin >> userInput; cin.ignore(100, '\n');
	}
	return userInput;
}

void connectFileToStream(string &fileName, ofstream &outputStream){
	getline(ws(cin), fileName);  //  move that tot the funciton
	outputStream.open(fileName);

	while (outputStream.fail()) {
		cout << "Error. The file names \"" << fileName << "\" could not be opened"
			<< "\nPlease enter the file name where you want to output the arrays: ";
		getline(ws(cin), fileName);
		outputStream.open(fileName);
	}
	
	/*if (outputStream.fail()) {
		cout << "Error. The file \"" << fileName << "\" could not be opened" << endl;

		cout << "Here are the text files you have in this directory:"  << endl << endl;

		system("DIR | FIND \".txt\"");

		system("pause");
		exit;
	}*/
}