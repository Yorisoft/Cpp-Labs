// In this lab exercise, you will calculate the monthly payment for a fixed-rate loan 
//
// Prof. Peter Morgan
// CSC237 Lab09: Pointers
// Yelsin Sepulveda
// November 22, 2020. 

// can be calculated as follows :
// monthlyPayment = (loanAmount ∗ monthlyInterestRate ∗ powerFactor)/ powerFactor − 1
// powerFactor = (1 + monthlyInterestRate)^numberOfPayments
// monthlyInterestRate = annualInterestRate / 12
// numberOfPayments = numberOfYears * 12

#include "Mortgage.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;


int main() {
	double years;
	long double loanAmount, iRate;
	string filename, choice = "y";
	ofstream outFile;
	Mortgage nMortgage;
	
	while (choice == "yes" || choice[0] == 'y') {
		cout << "Enter output file name: ";
		cin >> filename;

		cout << "Enter the amount of the loan: ";
		cin >> loanAmount;
		nMortgage.setLoanAmount(loanAmount);

		cout << "Enter the annual interest rate in decimal form (example .075): ";
		cin >> iRate;
		nMortgage.setMonthlyInterestRate(iRate);

		cout << "Enter the length of the loan in years: ";
		cin >> years;
		nMortgage.setNumberOfPayments(years);

		nMortgage.setMonthlyPayment();
		nMortgage.setTotalPaid();

		cout << endl << endl;
		cout << "Loan Amount          : $" << nMortgage.getloanAmount() << endl
		<< "Annual Interest Rate : " << nMortgage.getIRate() << endl
		<< "Years to repay       : " << years << endl
		<< "Monthly Payment      : $" << nMortgage.getMonthlyPayment() << endl
		<< "Total Pay Back       : $" << nMortgage.getTotalPaid() << endl;

		nMortgage.outputPaymentSchedule(outFile, filename);

		cout << "Do you wish to process another loan? (Y/n)";
		cin >> choice;
	}
	
	system("pause");
	return 0;
}