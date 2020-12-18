// This lab uses a switch-case , if .. else  statements and conditionla operators to determine what statements
// to process based on the package and songs entered.
// Switch Case Lab - Online Music Store Charge
// Developer Yelsin Sepulveda
// Last modified: 06/29/2017

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	system("TITLE Switch Case Lab - Online Music Store Charge - Yelsin S.");
	system("COLOR 70");

	const double
		PACKAGE_A_PRICE = 4.99,
		PACKAGE_B_PRICE = 9.99,
		PACKAGE_C_PRICE = 14.99,
		PACKAGE_A_PER_SONG = 0.99,
		PACKAGE_B_PER_SONG = 0.59,
		PACKAGE_C_PER_SONG = 0.29,
		SALES_TAX = 0.06;

	const int
		FREE_SONGS_A = 10,
		FREE_SONGS_B = 20,
		FREE_SONGS_C = 30;

	const char
		PACKAGE_A = 'A',
		PACKAGE_B = 'B',
		PACKAGE_C = 'C';

	int songsAfterFree;

	double songsDownloaded, total;

	char userPackage;

	cout << endl
		<< "\t\t\t               Switch Case GROUP Lab                 \n"
		<< "\t\t\t                Online music store                   \n"
		<< "\t\t\t     also needs nested if ... else statements        \n"
		<< "\t\t\t           and the conditional operator              \n"
		<< "\t\t\t   and the use of \"continue\" in one place ONLY     \n"
		<< "\t\t\t                   by Yelsin S.                      \n";

	while (true) {
		cout << endl
			<< "Here are the posible option packages offered in our store:\n"
			<< "\tPackage A: Monthly fee $ 4.99. 10 free songs and $0.99 per song after that. \n"
			<< "\tPackage B: Monthly fee $ 9.99. 20 free songs and $0.59 per song after that. \n"
			<< "\tPackage C: Monthly fee $14.99. 30 free songs and $0.29 per song after that. \n\n";

		cout << "Please select the option package that you have? ";
		cin >> ws; userPackage = getchar(); cin.ignore(100, '\n');      // Save user Package

		while (userPackage == '\n') {                                   // incase Package input is \n.
			userPackage = getchar(); cin.ignore(100, '\n');
		}
		switch (userPackage) {
		case 'a':
		case 'A': cout << "How many songs did you download this month? ";       // Ask user for songs downloaded
			cin >> songsDownloaded; cin.ignore(100, '\n');

			// songs downloaded minus free songs, using the value later to check if plural word will be needed.
			songsAfterFree = songsDownloaded - FREE_SONGS_A;

			// asigning value to int total, less typing later on.
			total = songsDownloaded <= FREE_SONGS_A ? PACKAGE_A_PRICE + (PACKAGE_A_PRICE * SALES_TAX) :
				(PACKAGE_A_PRICE + (PACKAGE_A_PER_SONG *(songsDownloaded - FREE_SONGS_A))) +
				SALES_TAX*(PACKAGE_A_PRICE + (PACKAGE_A_PER_SONG *(songsDownloaded - FREE_SONGS_A)));

			break;

		case 'b':
		case 'B': cout << "How many songs did you download this month? ";
			cin >> songsDownloaded; cin.ignore(100, '\n');

			// songs downloaded minus free songs, using the value later to check if plural word will be needed.
			songsAfterFree = songsDownloaded - FREE_SONGS_B;

			// asigning value to int total, less typing later on.
			total = songsDownloaded <= FREE_SONGS_B ? PACKAGE_B_PRICE + (PACKAGE_B_PRICE * SALES_TAX) :
				(PACKAGE_B_PRICE + (PACKAGE_B_PER_SONG *(songsDownloaded - FREE_SONGS_B))) +
				SALES_TAX*(PACKAGE_B_PRICE + (PACKAGE_B_PER_SONG *(songsDownloaded - FREE_SONGS_B)));

			break;

		case 'c':
		case 'C': cout << "How many songs did you download this month? ";
			cin >> songsDownloaded; cin.ignore(100, '\n');

			// songs downloaded minus free songs, using the value later to check if plural word will be needed.
			songsAfterFree = songsDownloaded - FREE_SONGS_C;

			// asigning value to int total, less typing later on.
			total = songsDownloaded <= FREE_SONGS_C ? PACKAGE_C_PRICE + (PACKAGE_C_PRICE * SALES_TAX) :
				(PACKAGE_C_PRICE + (PACKAGE_C_PER_SONG *(songsDownloaded - FREE_SONGS_C))) +
				SALES_TAX*(PACKAGE_C_PRICE + (PACKAGE_C_PER_SONG *(songsDownloaded - FREE_SONGS_C)));

			break;

		default: cout << "\t\t **** Sorry we do not offer that package. \n\n";

			system("PAUSE");

			cout << "\n\n ************************************************************ \n";

			continue;
		}
		if (userPackage == 'A' || userPackage == 'a') {													//if PACKAGE is A
			if (songsDownloaded <= FREE_SONGS_A && songsDownloaded >= 0) { 

				cout << fixed << setprecision(2);
				cout << "\n\nYour total bill for this month is $" << PACKAGE_A_PRICE << " + "
					<< (PACKAGE_A_PRICE * SALES_TAX) << " (for tax) = " << total << ". \n\n\n";
			}
			else if (songsDownloaded < 0) {												//if songs downloaded is NEGATIVE
				cout << "\t\t*** You can not have negative number of songs! \n\n";
			}
			else if (isalpha(songsDownloaded)) {							//if songs downloaded is not a digit numeral.
				cout << "\t\t*** Your number of songs needs to be a whole number! \n\n";
				system("pause");
			}
			else {
				cout << fixed << setprecision(2);												// if exceeds free songs
				cout << "\n\nYour total bill for this month is $"
					<< (PACKAGE_A_PRICE + (PACKAGE_A_PER_SONG *(songsDownloaded - FREE_SONGS_A)))
					<< " + " << SALES_TAX*(PACKAGE_A_PRICE + (PACKAGE_A_PER_SONG *(songsDownloaded - FREE_SONGS_A)))
					<< " (for tax) = " << total << ". \n";

				cout << "\t\t You have $" << (PACKAGE_A_PER_SONG *(songsDownloaded - FREE_SONGS_A))
					<< " extra charges for having " << setprecision(0) << (songsDownloaded - FREE_SONGS_A) << " more ";

				if (songsAfterFree > 1) {										//to determine if sons should be plural
					cout << "songs \n";
				}
				else {
					cout << "song \n";
				}

				cout << "\t\t than your monthly limit of " << FREE_SONGS_A << " free songs. \n\n\n";
			}

		}
		else if (userPackage == 'B' || userPackage == 'b') {											//if PACKAGE is A
			if (songsDownloaded <= FREE_SONGS_B && songsDownloaded >= 0) {
				cout << fixed << setprecision(2);
				cout << "\n\nYour total bill for this month is $" << PACKAGE_B_PRICE << " + "
					<< (PACKAGE_B_PRICE * SALES_TAX) << " (for tax) = " << total << ". \n\n\n";
			}
			else if (songsDownloaded < 0) {												//if songs downloaded is NEGATIVE
				cout << "\t\t*** You can not have negative number of songs! \n\n";
			}
			else if (isalpha(songsDownloaded)) {							//if songs downloaded is not a digit numeral.
				cout << "\t\t*** Your number of songs needs to be a whole number! \n\n";
				system("pause");
			}
			else {
				cout << fixed << setprecision(2);											// if user exceed free songs
				cout << "\n\nYour total bill for this month is $"
					<< (PACKAGE_B_PRICE + (PACKAGE_B_PER_SONG *(songsDownloaded - FREE_SONGS_B)))
					<< " + " << SALES_TAX*(PACKAGE_B_PRICE + (PACKAGE_B_PER_SONG *(songsDownloaded - FREE_SONGS_B)))
					<< " (for tax) = " << total << ". \n";

				cout << "\t\t You have $" << (PACKAGE_B_PER_SONG *(songsDownloaded - FREE_SONGS_B))
					<< " extra charges for having " << setprecision(0) << (songsDownloaded - FREE_SONGS_B) << " more ";

				if (songsAfterFree > 1) {										//to determine if sons should be plural
					cout << "songs \n";
				}
				else {
					cout << "song \n";
				}

				cout << "\t\t than your monthly limit of " << FREE_SONGS_B << " free songs. \n\n\n";
			}
		}
		else if (userPackage == 'C' || userPackage == 'c') {									//if PACKAGE is A

			if (songsDownloaded <= FREE_SONGS_C && songsDownloaded >= 0) {
				cout << fixed << setprecision(2);
				cout << "\n\nYour total bill for this month is $" << PACKAGE_C_PRICE << " + "
					<< (PACKAGE_C_PRICE * SALES_TAX) << " (for tax) = " << total << ". \n\n\n";
			}
			else if (songsDownloaded < 0) {												//if songs downloaded is NEGATIVE
				cout << "\t\t*** You can not have negative number of songs! \n\n";
			}
			else if (isalpha(songsDownloaded)) {							//if songs downloaded is not a digit numeral.
				cout << "\t\t*** Your number of songs needs to be a whole number! \n\n";
				system("pause");
			}
			else {
				cout << fixed << setprecision(2);											// if user exceed free songs
				cout << "\n\nYour total bill for this month is $"
					<< (PACKAGE_C_PRICE + (PACKAGE_C_PER_SONG *(songsDownloaded - FREE_SONGS_C)))
					<< " + " << SALES_TAX*(PACKAGE_C_PRICE + (PACKAGE_C_PER_SONG *(songsDownloaded - FREE_SONGS_C)))
					<< " (for tax) = " << total << ". \n";

				cout << "\t\t You have $" << (PACKAGE_C_PER_SONG *(songsDownloaded - FREE_SONGS_C))
					<< " extra charges for having " << setprecision(0) << (songsDownloaded - FREE_SONGS_C) << " more ";

				if (songsAfterFree > 1) {										//to determine if sons should be plural
					cout << "songs \n";
				}
				else {
					cout << "song \n";
				}

				cout << "\t\t than your monthly limit of " << FREE_SONGS_C << " free songs. \n\n\n";
			}
		}
		system("PAUSE");

		cout << "\n\n ************************************************************ \n";
	}
	return 0;
}