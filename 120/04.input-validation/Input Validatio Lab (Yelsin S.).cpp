// This Lab runs through a series of while loops as a method of input validation. 
// Input Validation Lab
// Developer: Yelsin Sepulveda
// Last modified: 07/03/17

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	system("TITLE Input Validation Lab by Yelsin S.");
	system("COLOR 70");

	double bottleInCase, bottlesBeingSold;

	cout << endl
		<< "\t\t This is program demonstrates how to use while() loop \n"
		<< "\t\t               for input validation                   \n"
		<< "\t\t                   by Yelsin S.                       \n";

	cout << endl
		<< "   **************************************************************************** \n"
		<< "   *  You should have ONLY ONE input validation loop for each input           * \n"
		<< "   *  Make sure you test ALL possible situations                              * \n"
		<< "   *  Consider using the conditional operator to customize your feedback      * \n"
		<< "   *  INSIDE the loop.                                                        * \n"
		<< "   **************************************************************************** \n\n\n";

	while (true) {

		// First Input
		cout << "How many bottle do you sell in a case? ";
		cin >> bottleInCase; cin.ignore(100, '\n');

		while (bottleInCase <= 0 || bottleInCase != (int)bottleInCase) {

			if (bottleInCase != (int)bottleInCase) {                                               // If input is NOT int

				cout << "\t" << fixed << setprecision(4) << bottleInCase
					<< " is NOT an interger. You can not have partial bottles in a case. \n";
	
			}
			else if (bottleInCase < 0) {                                                            // If input is < 0

				cout << " You cannot have negative bottles in a case! \n";
			}
			else if (bottleInCase == 0) {                                                            // If input is 0

				cout << "\t\t You can not sell empty case. \n";
			}

			cout << "Try again: ";
			cin >> ws >> bottleInCase;
		}

		//Second Input
		cout << "How many bottles does the customer want to buy? \n"
			<< "   Please note we sell ONLY whole cases, \n"
			<< "   so make sure you ONLY accept orders that are multile of " << fixed << setprecision(0) << bottleInCase
			<< ": ";
		cin >> bottlesBeingSold;  cin.ignore(100, '\n');

		while (bottlesBeingSold <= 0 || fmod(bottlesBeingSold, 1.0) > 0 || bottlesBeingSold / bottleInCase != (int)(bottlesBeingSold / bottleInCase)) {

			if (bottlesBeingSold < 0) {

				cout << " You cannot have negative bottles in a case! ";

				if (fmod(bottlesBeingSold, 1.0) > 0) {

					cout << "\t ALSO," << fixed << setprecision(1) << bottlesBeingSold
						<< " is NOT an interger. You can not have partial bottles in a case. ";
				}

			}
			else if (fmod(bottlesBeingSold, 1.0) > 0) {

				cout << "\t" << fixed << setprecision(1) << bottlesBeingSold
					<< " is NOT an interger. You can not have partial bottles in a case. \n";
			}
			else if (bottleInCase == 0) {

				cout << "\t\t You can not sell empty case. ";
			}
			else if (bottlesBeingSold / bottleInCase != (int)(bottlesBeingSold / bottleInCase)) {

				cout << "\t\t You can only place orders in whole cases. ";
			}

			cout << "Try again: ";
			cin >> ws >> bottlesBeingSold;
		}

		cout << endl
			<< "\n Congraduatlions you sold " << bottlesBeingSold << (bottlesBeingSold > 1 ? " bottles" : " bottle")
			<< ",  which you can fit in excaclty " << bottlesBeingSold / bottleInCase << " " << (bottlesBeingSold / bottleInCase > 1 ? "cases" : "case") << " of "
			<< bottleInCase << (bottlesBeingSold > 1 ? " bottles" : " bottle") << " each! \n\n"
			<< endl;

		system("pause");

		cout << "\n\n \t\t****************************************************** \n\n";

	}
	return 0;
}