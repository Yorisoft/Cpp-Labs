// In this lab you will need to enter the "number" as a STRING.
// Title: Flip Flop Capstone
// Programmer: Telma Zelaya and Yelsin Sepulveda
// Last update 08/18/2017

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Prototype Functions
string getValidLargeInteger();
bool hasSign(string num);
int sumOfDigits(string num);
int lastDigitValue(string num);
bool isValidLargeInteger(string num);
void printBanner(ostream& os = cout);
void printInstructions(ostream& os = cout);
void connectOutStream(ofstream& output, string& fileName);
void printResults(string num, ostream& output = cout);
int findDigitValue(char ch);
bool isDivisibleBy3(string num);
bool isDivisibleBy5(string num);

int main()
{
	string fileName, number;
	ofstream output;

	system("color 30");
	system("title Flip Flop capstone ( Telma and Yelsin )");

	printBanner();
	printInstructions();

	cout << "\nWhat is the filename you want to store your output? ";
	getline(cin >> ws, fileName);

	connectOutStream(output, fileName);

	printBanner(output);
	printInstructions(output);

	cout << "\n\nWhat is your number? ";
	number = getValidLargeInteger();

	while (cin)
	{
		output << "\n         Your number was " << number << "\n";
		printResults(number);
		printResults(number, output);

		cout << "\nWhat is your number? ";
		number = getValidLargeInteger();
	}
	output.close();

	cin.clear();
	cout << "\n     ***  Program about to end.Your output can be found in " << fileName << " \n";
	cout << "Hit ENTER to terminate. ";
	cin.get();

	return 0;
}


void printBanner(ostream& os)
{
	os
		<< "\n"
		<< "                                 Flip Flop                                 \n"
		<< "          for VERY Large Numbers that would overflow any type of int       \n"
		<< "                    accepts signs at the begining of the num               \n"
		<< "                               Sample Solution                              \n"
		<< "                               Using Functions                              \n"
		<< "                             by Telma and Yelsin                            \n\n\n";

}


// Get Valid Large Integer 
string getValidLargeInteger()
{
	string input;
	getline(cin >> ws, input);

	while (!isValidLargeInteger(input) && cin)
	{
		cout << "     Please provide a legal number."
			<< "\n\nWhat is your number? ";
		getline(cin >> ws, input);
	}
	return input;
}

// DONE 
bool hasSign(string num)
{
	if (num[0] == '+' || num[0] == '-') return true;
	return false;
}

// Sum of Digits 
int sumOfDigits(string num)
{
	int total = 0, start = 0, end = num.size();
	if (hasSign(num)) start = 1;

	while (start < end)
	{
		total += findDigitValue(num[start]);
		start++;
	}
	return total;
}

// Last Digit Value
int lastDigitValue(string num)
{
	return findDigitValue(num[num.size() - 1]);
}

// Is Valid Large Integer... For loop 
bool isValidLargeInteger(string num)
{
	int start = 0, end = num.size();

	if (hasSign(num)) start = 1;   //starts from element 1 if the element 0 is a valid sign

	if (hasSign(num) && num.size() == 1) //returns false if the string contains only sign
		return false;

	while (start < end)
	{
		if (num[start] < '0' || num[start] > '9') return false;
		start++;
	}
	return true;
}

void connectOutStream(ofstream& output, string& fileName) {
	output.open(fileName);

	while (output.fail())
	{
		cout << "Failed to open the output file " << fileName << "."
			<< "\nPlease provide a different filename : ";
		getline(cin >> ws, fileName);
		output.open(fileName);
	}
}

void printInstructions(ostream& os)
{
	os << "This program prints:\n"
		<< "     \"Flop\" if a number is divisible by 3\n"
		<< "     \"Flip\" if divisible by 5 and\n"
		<< "     \"Flip Flop\" if divisible by BOTH 5 and 3\n"
		<< "      nothing if divisible by NEITHER\n";
}

void printResults(string num, ostream& output) {

	int sum = sumOfDigits(num), lastDigit = lastDigitValue(num);

	output << "\t ";
	if (isDivisibleBy5(num) || isDivisibleBy3(num))
	{
		output << (isDivisibleBy5(num) ? "Flip " : "")
			<< (isDivisibleBy3(num) ? "Flop" : "");
	}

	output
		<< "\n\n\t Debugging couts in main:\n"
		<< "\t The int value of the last digit in \"num\" \n"
		<< "\t\t (here call the corresponding function) is " << lastDigit << ".\n"
		<< "\t The sum of digits in \"num\"\n"
		<< "\t\t (here call the corresponding function) is " << sum << ".\n\n"
		<< "\t     *******************************************   " << endl;

}

int findDigitValue(char ch)
{
	return ch - '0';
}

bool isDivisibleBy3(string num) {
	return sumOfDigits(num) % 3 == 0;
}

bool isDivisibleBy5(string num) {
	return (findDigitValue(num[num.length() - 1]) == 0 || findDigitValue(num[num.length() - 1]) == 5);
}