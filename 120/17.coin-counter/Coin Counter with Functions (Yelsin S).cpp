// This lab uses 4 functions. a print function, a Switch Case functions and two function used for 
// input validation. The purpose of this lab is to count up to a user defined limit using only coins.
// Coin Counter
// Developed by: Yelsin Sepulveda
// Last modified: Aug 9th, 2017.

#include<iostream>
using namespace std;

void printBanner();
int getPosInt();
char getValidCoin();
int getCoinValue(char coin);

int main() {
	system("TITLE		Coin Counter                  By Yelsin S");
	system("COLOR 70");

	int coinLimit, currentTotal, coinsUsed;
	char usersCoin;

	printBanner();

	while (true) {
		currentTotal = 0;
		coinsUsed = 0;

		cout << "What is the amount you would like to reach? ";
		coinLimit = getPosInt();

		while (currentTotal < coinLimit) {
			cout << "What coin did you get? ";
			usersCoin = getValidCoin();

			cout << "   **   '" << usersCoin << "':     coin value is :   " << getCoinValue(usersCoin)
				<< "     current total:     " << (currentTotal += getCoinValue(usersCoin)) << "c \n";

			coinsUsed += 1;
		}
		cout << "\nYour total amoun is: " << currentTotal << ". \n" << "It took " << coinsUsed
			<< (coinsUsed == 1 ? " coin " : " coins ") << "to reach " << coinLimit
			<< (coinLimit == 1 ? " cent " : " cents ") << "\n";

		if (currentTotal > coinLimit)
			cout << "You have " << currentTotal - coinLimit << " more" << (currentTotal - coinLimit == 1 ? " cent " : " cents ")
			<< "than your goal was! \n\n";

		cout << "\n\t\t************	\n\n";

	}
	return 0;
}

void printBanner() {
	cout << endl
		<< "\t                   Programming                     \n"
		<< "\t  Coin total with functions and input validation   \n"
		<< "\t                 Sample solution                   \n"
		<< "\t                   by Yelsin S.                    \n\n";
}

int getPosInt() {
	double posInt;
	cin >> posInt; cin.ignore(100, '\n');

	while (posInt < 0 || posInt > (static_cast<int>(posInt))) {
		cout << "\tPlease enter a ";
		cout << (posInt == ((int)posInt) ? "" : "whole ");
		cout << (posInt < 0 ? "positive " : "") << "number. Try again : ";
		cin >> posInt; cin.ignore(100, '\n');
	}
	return posInt;
}

char getValidCoin() {
	char validCoin;
	cin >> validCoin; cin.ignore(100, '\n');

	while (!(validCoin == 'P' || validCoin == 'p' || validCoin == 'N' || validCoin == 'n' ||
		validCoin == 'D' || validCoin == 'd' || validCoin == 'Q' || validCoin == 'q')) {
		cout << "\t'" << validCoin << "'  *** Invalid coin *** \n What coin did you get? ";
		cin >> validCoin; cin.ignore(100, '\n');
	}
	return validCoin;
}

int getCoinValue(char coin) {
	switch (coin) {
	case 'P':	case 'p':	return 1;
	case 'N':	case 'n':	return 5;
	case 'D':	case 'd':	return 10;
	case 'Q':	case 'q':	return 25;
	}
}