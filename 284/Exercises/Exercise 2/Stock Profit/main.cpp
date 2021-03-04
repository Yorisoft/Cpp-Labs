// Stock Profit - Excersice 2
// Create a program that calculates the profits ( or losses  ) of a stock for the users.
// Prof Carmelito Moreno - CSC 284-H1
// Yelsin Sepulveda

#include<iostream>
#include<iomanip> 
#include<string>
#include<vector>
using namespace std;

void printHeader();
double calculaterEarnings(double numOfShare, double saleShare, double saleComPaid, double purchasePrice, double purchaseComm);

int main() {
	system("color 70");
	cout << fixed << setprecision(2);

	string choice = "yes";
	double numOfShare, saleShare, saleComPaid,
		purchasePrice, purchaseComm, earnings;

	while (choice[0] == 'y' || choice[0] == 'Y') {
		printHeader();
		// Profit = ((NS * SP) - SC) - ((NS * PP) + PC)
		// NS = Number of shares
		// SP = Sale per share
		// SC = Sales commision paid
		// PP = Purchase price per share
		// PC = Purchase commision paid

		cout << "What is the NS? ";
		cin >> numOfShare; cin.ignore(100, '\n');

		cout << "What is the SP? ";
		cin >> saleShare; cin.ignore(100, '\n');

		cout << "What is the SC? ";
		cin >> saleComPaid; cin.ignore(100, '\n');

		cout << "What is the PP? ";
		cin >> purchasePrice; cin.ignore(100, '\n');

		cout << "What is the PC? ";
		cin >> purchaseComm; cin.ignore(100, '\n');

		earnings = calculaterEarnings(numOfShare, saleShare, saleComPaid, purchasePrice, purchaseComm);
		
		cout << endl << "Your earning were calculated to be at " << earnings << endl;

		cout << "Would you like to run the program again ? [Y/n] ";
		getline(cin, choice);
	}

	system("pause");
	return 0;
}

void printHeader() {
	cout << endl << "\t\t" 
		<< "This program calculates the profits ( or losses  ) of a stock for the users" << endl
		<< "NS = Number of shares" << endl
		<< "SP = Sale per share" << endl
		<< "SC = Sales commision paid" << endl
		<< "PP = Purchase price per share" << endl
		<< "PC = Purchase commision paid" << endl << endl;
}

double calculaterEarnings(double numOfShare, double saleShare, double saleComPaid, double purchasePrice, double purchaseComm) {
	return ((numOfShare * saleShare) - saleComPaid) - ((numOfShare * purchasePrice) + purchaseComm);
}