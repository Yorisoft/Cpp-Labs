// This lab is a capstone and includes everything I've learned this semester.
// This lab prints out "FLip" if it is divisible by 3 and "Flop" if divisible by 5.
// Flip Flop Individual
// Developed by: Yelsin Sepulveda
// Last modified: August 21, 2017

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// prototype are done
void printBanner(ostream &outputStream = cout);
void printInstructions(ostream &outputStream = cout);
void printResults(string num, ostream &outputStream = cout);
void connectOutStream(string &fileName, ofstream &outStream);
string getValidLargeInteger();
bool isValidLargeInteger(string num);
bool isDivisibleBy3(string num);
bool isDivisibleBy5(string num);
bool hasSign(string num);
int findDigitValue(char digit);
int lastDigitValue(string num);
int sumOfDigits(string num);


int main() {
	system("TITLE  Flip Flop Individual		 By Yelsin S");
	system("COLOR 70");

	ofstream fileOutput;
	string fileName, numberInput;

	printBanner();
	printInstructions();
		
	cout << "What is the filename you want to store your output? ";
	connectOutStream(fileName, fileOutput);

	cout << endl << "What is your number? ";
	numberInput = getValidLargeInteger();

	while(cin) {
		printResults(numberInput);
		printResults(numberInput, fileOutput);

		cout << endl << "What is your number? ";
		numberInput = getValidLargeInteger();

	}
	fileOutput.close();
	 
	cout << "\t*** Program about to end. Your output can be found in " << fileName << '.' << endl
	<< "Hit ENTER to terminate: " << endl;

	cin.clear(); cin.ignore(100, '\n');

	return 0;
}

void printBanner(ostream &outputStream) {  // done
	outputStream << endl
		<< "\t                       Flip Flop                            \n"
		<< "\t for VERY Large Numbers that would overflow any type of int \n"
		<< "\t          accepts sings at the begining of the num          \n"
		<< "\t                   Individual solution                      \n"
		<< "\t                     Using Functions                        \n"
		<< "\t                       by Yelsin S.                         \n"
		<< endl << endl << endl;
}

void printInstructions(ostream &outputStream) {  // done
	outputStream << "This program prints: \n"
		<< "\t\"Flop\" if a number is divisible by 3 \n"
		<< "\t\"Flip\" if divisible by 5 and \n"
		<< "\t\"Flip Flop\" if divisible by BOTH 5 and 3 \n"
		<< "\tnothing if divisible by NEITHER" << endl << endl;
}

void connectOutStream(string &fileName, ofstream &outStream) {  // done
	getline(ws(cin), fileName);
	outStream.open(fileName);

	while (outStream.fail()) {
		cout << "Failed to open the output file " << fileName << ".\n"
			<< "Please provide a diffrent filename: ";
		getline(ws(cin), fileName);
		outStream.open(fileName);
	}
}

string getValidLargeInteger() {  // done
	string input;
	getline(ws(cin), input);

	while (!isValidLargeInteger(input) && cin) {
		cout << "\tYour number contains illigal digits \n\n"
			<< "What is your number? ";
		getline(cin >> ws, input);
	}
	return input;	
}

bool isValidLargeInteger(string num) {
	int x = (hasSign(num) ? 1 : 0);

	if (hasSign(num)  && num.size() == 1)
		return false;

	for (; x < num.length(); x++)
		if (num[x] < '0' || num[x] > '9')
			return false;

	return true;
}

bool hasSign(string num) {
	return num[0] == '+' || num[0] == '-';
}

bool isDivisibleBy3(string num) {  // done
	return sumOfDigits(num) % 3 == 0;
}

int findDigitValue(char digit) {		 // subtracting ascii values and typecasting to int.  done
	return digit - '0';
}

bool isDivisibleBy5(string num) {  // done
//	int x = num.length();
//	return ((num[x - 1] - '0') == 0) || ((num[x - 1] - '0') == 5);  // make 1 line and call the findLastDigitVal
	return (findDigitValue(num.length() - 1) == 0 || findDigitValue(num.length() - 1) == 5);
}

void printResults(string num, ostream &outputStream) {   // done
	outputStream << "Your number was " << num << endl;

	outputStream << "\t" << (isDivisibleBy5(num) ? "Flip " : "")
		<< (isDivisibleBy3(num) ? "Flop " : "") << '\n';

	outputStream << "\tDebugging couts in printResults function:\n"
		<< "\tThe int value of the last digit in \"num\"\n"
		<< "\t\t(here call the corresponding function)" << " is " << lastDigitValue(num) << endl
		<< "\tThe sum of digits in \"num\"\n"
		<< "\t\t(here call the corresponding function)" << " is " << sumOfDigits(num) << endl
		<< endl << "\t****************************************************\n";
} 

int lastDigitValue(string num) {     // call the findDigitval
	return (findDigitValue(num[num.length() - 1]));		
}

int sumOfDigits(string num) {
	int x, digitSum = 0;

	hasSign(num) == true ? x = 1 : x = 0;

	for (; num[x] != '\0'; x++)
		digitSum += findDigitValue(num[x]);

	return digitSum;
}