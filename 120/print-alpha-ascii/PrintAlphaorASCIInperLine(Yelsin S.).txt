// This lab uses a rang of integer values to print characters from the ASCII character table. 
// It uses a switch cases to determine the characters and range to be printed, 
// aswell as a for loop to print out the characters. 
// Print Alpha or ASCII n per Line
// Yelsin Sepulveda
// Last modified: July 7, 2017

#include<iostream>
#include<iomanip>
using namespace std;

int main() {

	system("TITLE Print Alpha or ASCII n per Line   by Yelsin S.");
	system("COLOR 70");

	const int
		MIN_LINES = 1,
		MAX_LINES = 4,
		ASCII_COMPLETE_START = 0,
		ASCII_COMPLETE_END = 225,
		ASCII_DIGITS_START = 48,
		ASCII_DIGITS_END = 57,
		ASCII_CAPS_START = 65,
		ASCII_CAPS_END = 90,
		ASCII_LOWER_START = 97,
		ASCII_LOWER_END = 122;

	int tableChosen, linesChosen, asciiCharstart, asciiCharend, asciiChar;

	cout << endl
		<< "\t\t\t      Print the WHOLE ASCII table or the Alphabet    \n"
		<< "\t\t\t                n characters per line                \n"
		<< "\t\t\t                     By Yelsin S.                    \n\n\n";

	while (true) {
		cout << "Please enter your choice: \n"
			<< "\t1] Print the whole ASCII table \n"
			<< "\t2] Print the capital letters \n"
			<< "\t3] Print the lower letters \n"
			<< "\t4] Print the digits \n"
			<< "\t5] Exit the program \n"
			<< "choice: ";
		cin >> tableChosen; cin.ignore(100, '\n');											// User table choice

		switch (tableChosen) {																// Assigning range of ascii characters to print
		case 1:asciiCharstart = ASCII_COMPLETE_START;
			asciiCharend = ASCII_COMPLETE_END;
			break;
		case 2: asciiCharstart = ASCII_CAPS_START;
			asciiCharend = ASCII_CAPS_END;
			break;
		case 3:asciiCharstart = ASCII_LOWER_START;
			asciiCharend = ASCII_LOWER_END;
			break;
		case 4:asciiCharstart = ASCII_DIGITS_START;
			asciiCharend = ASCII_DIGITS_END;
			break;
		case 5: cout << "\nThank you for using printing with us. Please hit ENTER to end the program.";
			cin.get();
			return 0;
			break;
		}
		cout << endl << "How many characters do you want to print per line? ";				// User line choice
		cin >> linesChosen; cin.ignore(100, '\n');

		while (linesChosen < 1 || linesChosen > 4) {											// While choise is NOT 1-4.
			if (linesChosen < 0) {
				cout << "\tYour number must be greater than or equal to 0. \n"
					<< "\tTry again: ";
				cin >> linesChosen; cin.ignore(100, '\n');
			}else  /*(linesChosen >= 0)*/ {
				cout << "\tYour number must be less than or equal to 4. \n"
					<< "\tTry again: ";
				cin >> linesChosen; cin.ignore(100, '\n');
			}
		}
		for (int perLine = 1, asciiChar = asciiCharstart; asciiChar <= asciiCharend; asciiChar++, perLine++) {

			cout << setw(3) << right << asciiChar << setw(3) << ' ' << setw(4) << right;
			switch (asciiChar)
			{
			case 0: cout << "NULL"; break;
			case 7:	cout << "\\a";	break;
			case 8:	cout << "\\b";	break;
			case 9:	cout << "\\t";	break;
			case 10: cout << "\\n";	break;
			case 11: cout << "\\u";	break;
			case 13: cout << "\\r";	break;
			default: cout << (char)asciiChar;
				break;
			}
			cout << setw(3) << right << (perLine % linesChosen == 0 ? "\n" : "||");
		}
		cout << endl;

		system("PAUSE");

		cout << endl;
	}
	return 0;
}
