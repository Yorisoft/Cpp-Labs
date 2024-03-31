//
// Online Music Store __ Practice quiz (Yelsin S)
// Developed by: Yelsin S
// Last modified: 8 1, 2017

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void printBanner();
int getPosInt();
char getValidPackage();


int main() {
	system("TITLE Switch Case lab Online Music Store			By Yelsin S");
	system("COLOR 70");

	const char
		PACKAGE_A = 'A',
		PACKAGE_B = 'B',
		PACKAGE_C = 'C';
	const double
		MONTHLY_FEE_A = 4.99,
		MONTHLY_FEE_B = 9.99,
		MONTHLY_FEE_C = 14.99,
		PER_SONG_A = 0.99,
		PER_SONG_B = 0.59,
		PER_SONG_C = 0.29;
	const int
		FREE_SONGS_A = 10,
		FREE_SONGS_B = 20,
		FREE_SONGS_C = 30;

	int songsDownld, freeSongs;
	double monthlyFee, perExtraSongs;
	char userPackage;

	printBanner();

	while (true) {
		cout << "Here are the possible packages offered in out store: \n"
			<< "  Package " << PACKAGE_A << " : Monthly fee $ " << MONTHLY_FEE_A << ". " << FREE_SONGS_A << " free songs and $" << PER_SONG_A << " per song after that.\n"
			<< "  Package " << PACKAGE_B << " : Monthly fee $ " << MONTHLY_FEE_B << ". " << FREE_SONGS_B << " free songs and $" << PER_SONG_B << " per song after that.\n"
			<< "  Package " << PACKAGE_C << " : Monthly fee $" << MONTHLY_FEE_C << ". " << FREE_SONGS_C << " free songs and $" << PER_SONG_C << " per song after that.\n";

		cout << "\nPlease select the option package that you have: ";
		userPackage = getValidPackage();

		cout << "\nHow many songs did you download this month? ";
		songsDownld = getPosInt();

		switch (userPackage) {
		case PACKAGE_A:
		case 'a':  
			monthlyFee = MONTHLY_FEE_A;
			perExtraSongs = PER_SONG_A;
			freeSongs = FREE_SONGS_A;
			break;
		case PACKAGE_B:
		case 'b':
			monthlyFee = MONTHLY_FEE_B;
			perExtraSongs = PER_SONG_B;
			freeSongs = FREE_SONGS_B;
			break;
		case PACKAGE_C:
		case 'c':
			monthlyFee = MONTHLY_FEE_C;
			perExtraSongs = PER_SONG_C;
			freeSongs = FREE_SONGS_C;
			break;
		}

			if (songsDownld > freeSongs) {
				cout << "Your total bill for this month is "
					<< MONTHLY_FEE_A + ((songsDownld - FREE_SONGS_A)*PER_SONG_A) << " + " << setprecision(2) << fixed
					<< (MONTHLY_FEE_A + ((songsDownld - FREE_SONGS_A)*PER_SONG_A))*(6.0 / 100) << " (for tax) = "
					<< MONTHLY_FEE_A + ((songsDownld - FREE_SONGS_A)*PER_SONG_A) + (MONTHLY_FEE_A + ((songsDownld - FREE_SONGS_A)*PER_SONG_A))*(6 / 100)
					<< " .\n";

				cout << "\t You have $" << (songsDownld - FREE_SONGS_A)*PER_SONG_A << " for having "
					<< songsDownld - FREE_SONGS_A << " more " << (songsDownld - FREE_SONGS_A > 1 ? "songs\n" : "song\n")
					<< "\t than your monthly limit of " << FREE_SONGS_A << " free songs. \n\n";


			}
			else {
				cout << "Your total bill for this month is " << MONTHLY_FEE_A << " + " << setprecision(2) << fixed
					<< (MONTHLY_FEE_A * 6 / 100) << " (for tax) = " << MONTHLY_FEE_A + (MONTHLY_FEE_A * 6 / 100) << " .\n\n";


			}
		} if (userPackage == PACKAGE_B || userPackage == 'b') {
			if (songsDownld > FREE_SONGS_B) {
				cout << "Your total bill for this month is "
					<< MONTHLY_FEE_B + ((songsDownld - FREE_SONGS_B)*PER_SONG_B) << " + " << setprecision(2) << fixed
					<< (MONTHLY_FEE_B + ((songsDownld - FREE_SONGS_B)*PER_SONG_B))*(6.0 / 100) << " (for tax) = "
					<< MONTHLY_FEE_B + ((songsDownld - FREE_SONGS_B)*PER_SONG_B) + (MONTHLY_FEE_B + ((songsDownld - FREE_SONGS_B)*PER_SONG_B))*(6 / 100)
					<< " .\n";

				cout << "\t You have $" << (songsDownld - FREE_SONGS_B)*PER_SONG_B << " for having "
					<< songsDownld - FREE_SONGS_B << " more " << (songsDownld - FREE_SONGS_A > 1 ? "songs\n" : "song\n")
					<< "\t than your monthly limit of " << FREE_SONGS_B << " free songs. \n\n";


			}
			else {
				cout << "Your total bill for this month is " << MONTHLY_FEE_B << " + " << setprecision(2) << fixed
					<< (MONTHLY_FEE_B * 6 / 100) << " (for tax) = " << MONTHLY_FEE_B + (MONTHLY_FEE_B * 6 / 100) << " .\n\n";


			}
		} if (userPackage == PACKAGE_C || userPackage == 'c') {
			if (songsDownld > FREE_SONGS_C) {
				cout << "Your total	bill for this month is "
					<< MONTHLY_FEE_C + ((songsDownld - FREE_SONGS_C)*PER_SONG_C) << " + " << setprecision(2) << fixed
					<< (MONTHLY_FEE_C + ((songsDownld - FREE_SONGS_C)*PER_SONG_C))*(6.0 / 100) << " (for tax) = "
					<< MONTHLY_FEE_C + ((songsDownld - FREE_SONGS_C)*PER_SONG_C) + (MONTHLY_FEE_C + ((songsDownld - FREE_SONGS_C)*PER_SONG_C))*(6 / 100)
					<< " .\n";

				cout << "\t You have $" << (songsDownld - FREE_SONGS_C)*PER_SONG_C << " for having "
					<< songsDownld - FREE_SONGS_C << " more " << (songsDownld - FREE_SONGS_A > 1 ? "songs\n" : "song\n")
					<< "\t than your monthly limit of " << FREE_SONGS_C << " free songs. \n\n";


			}
			else {
				cout << "Your total	bill for this month is " << MONTHLY_FEE_C << " + " << setprecision(2) << fixed
					<< (MONTHLY_FEE_C * 6 / 100) << " (for tax) = " << MONTHLY_FEE_C + (MONTHLY_FEE_C * 6 / 100) << " .\n\n";

			}

		}
		cout << endl << endl;

		system("PAUSE");

		cout << "\n******************************************************************************\n\n";

	}

	return 0;
}

void printBanner() {
	cout << endl
		<< "\t\t             Swith Case INDIVIDUAL Lab             \n"
		<< "\t\t                On line music store                \n"
		<< "\t\t                  with FUNCTIONS                   \n"
		<< "\t\t     also needs nester if ... else statements      \n"
		<< "\t\t           and the conditional operator            \n"
		<< "\t\t                   By Yelsin S.                    \n"
		<< endl << endl;
}

int getPosInt() {
	double posDouble;
	cin >> posDouble;

	while (!(posDouble == (int)posDouble) || posDouble < 0) {
		if (posDouble < 0) {
			cout << "\n\tPlease enter a positive number. Try again: ";
			cin >> posDouble;
		}
		if (!(posDouble == (int)posDouble)) {
			cout << "\n\tPlease enter a whole numebr. Try again: ";
			cin >> posDouble;
		}
		
	}
	return (int)posDouble;
}

char getValidPackage() {
	char validPackage;
	cin >> validPackage;

	while (!(validPackage == PACKAGE_A || validPackage == 'a' || validPackage == PACKAGE_B
		|| validPackage == 'b' || validPackage == PACKAGE_C || validPackage == 'c')) {

		cout << "Invalid Package. Please try again: ";
		cin >> validPackage; cin.ignore(100, '\n');
	}
	return validPackage;
}

