// Bank Accounts - Project 1 
// This program uses three classes to emulate a Savings and Chenckings account. 
// Prof Carmelito Moreno - CSC 284-H1
// Yelsin Sepulveda

#include<iostream>
#include<iomanip>
#include<string>
#include "GenericAccount.h"
#include "SavingsAccount.h"
#include "CheckingsAccount.h"
#include "InactiveAccount.h"
using namespace std;

void printBanner();
void printInterface();
void savingDeposite(SavingsAccount* nSavingsAccountPtr);
void savingWithdrawl(SavingsAccount* nSavingsAccountPtr);
void checkingDeposite(CheckingsAccount* nCheckingAccountPtr);
void checkingWithdrawl(CheckingsAccount* nCheckingAccountPtr);
void printEndOfMonth(CheckingsAccount* nCheckingAccountPtr, SavingsAccount* nSavingsAccountPtr, long double& startingCheckingBalance, long double& startingSavingBalance);

int main() {
	string choice = "yes";
	int transaction;
	double APR;
	long double startingCheckingBalance, startingSavingBalance;
	CheckingsAccount* CheckingAccountPtr = NULL;
	SavingsAccount* SavingsAccountPtr = NULL;

	printBanner();

	cout << "What would you like as your starting balance for your Checking account ?? ( Minimum of $25 to activate account)  ";
	cin >> startingCheckingBalance; cin.ignore(100, '\n');

	cout << "What would you like as your starting balance for your Savings account ?? ( Minimum of $25 to activate account)  ";
	cin >> startingSavingBalance; cin.ignore(100, '\n');

	cout << "What is the annual interest rate for your Savings account?? ";
	cin >> APR; cin.ignore(100, '\n');

	// Initializing new checking and savings account object
	CheckingAccountPtr = new CheckingsAccount(startingCheckingBalance, APR);
	SavingsAccountPtr = new SavingsAccount(startingSavingBalance, APR);

	while (choice[0] == 'y' || choice[0] == 'Y') {		
		try {
			printInterface();

			cout << "What transaction would you like to performe ? (1 - 5) ";
			cin >> transaction;

			switch (transaction) {
				case 1:	checkingDeposite(CheckingAccountPtr);
					cout << "New Balance: " << CheckingAccountPtr->getBalance() << endl << endl;
					break;
				case 2: checkingWithdrawl(CheckingAccountPtr);
					cout << "New Balance: " << CheckingAccountPtr->getBalance() << endl << endl;
					break;
				case 3: savingDeposite(SavingsAccountPtr);
					cout << "New Balance: " << SavingsAccountPtr->getBalance() << endl << endl;
					break;
				case 4: savingWithdrawl(SavingsAccountPtr);
					cout << "New Balance: " << SavingsAccountPtr->getBalance() << endl << endl;
					break;
				case 5: printEndOfMonth(CheckingAccountPtr, SavingsAccountPtr, startingCheckingBalance, startingSavingBalance);	
					return 0;  break;
				default: cout << "Invalid selection.. Try again.." << endl << endl;
					break;
			}
		}
		catch (InactiveAccount& e) {
			cout << "Coule not Complete transaction " << endl
				<< '\t' << e.getError() << endl;
		}

		cout << "Would you like to enter another transaction ? [Y/n] ";
		cin.ignore(100, '\n'); getline(cin, choice);
	}

	system("pause");
	return 0;
}

void printBanner() {
	cout << "\t\t        This program emulates the functionality of both a Checkings       " << endl
		<< "\t\t && Savings bank account, then prints out an End-Of-Month review message " << endl << endl;
}
void printInterface() {
	cout << "Select one of these options: " << endl
		<< '\t' << "1. Deposite into Checking Account " << endl
		<< '\t' << "2. Withraw from Checking Account " << endl
		<< '\t' << "3. Deposite into Savings Account " << endl
		<< '\t' << "4. Withraw from Savings Account " << endl
		<< '\t' << "5. Print out End-Of-Month review message " << endl << endl;
}
void checkingDeposite(CheckingsAccount* nCheckingAccountPtr) {
	long double newDeposite;

	cout << "How much would you like to deposite into your checkings account ? ";
	cin >> newDeposite;

	nCheckingAccountPtr->deposit(newDeposite);
}
void checkingWithdrawl(CheckingsAccount* nCheckingAccountPtr) {
	long double newWithdrawl;

	try {
		cout << "How much would you like to withdraw from your checkings account ? ";
		cin >> newWithdrawl;

		nCheckingAccountPtr->withdraw(newWithdrawl);

		cout << "Finished trasaction.." << endl;
	}
	catch (InactiveAccount& e) {
		throw e;
	}

}
void savingDeposite(SavingsAccount* nSavingsAccountPtr) {
	long double newDeposite;

	try {
		cout << "How much would you like to deposite into your savings account ? ";
		cin >> newDeposite;

		nSavingsAccountPtr->deposit(newDeposite);
	}
	catch (InactiveAccount& e) {
		throw e;
	}
}
void savingWithdrawl(SavingsAccount* nSavingsAccountPtr) {
	long double newWithdrawl;

	try {
		cout << "How much would you like to withdraw from your savings account ? ";
		cin >> newWithdrawl;

		nSavingsAccountPtr->withdraw(newWithdrawl);

		cout << "Finished trasaction.." << endl;
	}
	catch (InactiveAccount& e) {
		throw e;
	}

}
void printEndOfMonth(CheckingsAccount* nCheckingAccountPtr, SavingsAccount* nSavingsAccountPtr, long double& startingCheckingBalance, long double& startingSavingBalance) {
	int accountChosen;

	cout << "What account would you like to print?" << endl
		<< "1. Checkings " << endl
		<< "2. Savings " << endl;
	cin.ignore(100, '\n'); cin >> accountChosen;

	if (accountChosen == 1) {
		// Checkings
		cout << "This is your end of month review: " << endl
			<< "\t" << "Checking Account: " << endl
			<< "\t\t" << "Starting Balance: " << startingCheckingBalance << endl
			<< "\t\t" << "Total Num. of deposites: " << nCheckingAccountPtr->getNumOfDeposites() << endl
			<< "\t\t" << "Total Num. of withdrawls: " << nCheckingAccountPtr->getNumOfWithdrawls() << endl;
		nCheckingAccountPtr->monthlyProc();
		cout << "\t\t" << "Service Fees:       -" << nCheckingAccountPtr->getServiceCharge() << endl
			<< "\t\t" << "Monthly Overdrafts: -" << nCheckingAccountPtr->getMonthlyOverdraft() << endl
			<< "\t\t" << "Total in Fees and Overdraft: -" << (nCheckingAccountPtr->getServiceCharge() + nCheckingAccountPtr->getMonthlyOverdraft()) << endl
			<< "\t\t" << "Ending Balance: " << nCheckingAccountPtr->getBalance() << endl << endl;
	}
	else {
		// Savings
		cout << "\t" << "Savings Account: " << endl
			<< "\t\t" << "Starting Balance: " << startingSavingBalance << endl
			<< "\t\t" << "Total Num. of deposites: " << nSavingsAccountPtr->getNumOfDeposites() << endl
			<< "\t\t" << "Total Num. of withdrawls: " << nSavingsAccountPtr->getNumOfWithdrawls() << endl;
		nSavingsAccountPtr->monthlyProc();
		cout << "\t\t" << "Service Fees:      " << nSavingsAccountPtr->getServiceCharge() << endl
			<< "\t\t" << "Monthly Overdrafts: " << nSavingsAccountPtr->getMonthlyOverdraft() << endl
			<< "\t\t" << "Total in Fees and Overdraft: " << (nSavingsAccountPtr->getServiceCharge() + nSavingsAccountPtr->getMonthlyOverdraft()) << endl
			<< "\t\t" << "Ending Balance: " << nSavingsAccountPtr->getBalance() << endl << endl;

	}
}