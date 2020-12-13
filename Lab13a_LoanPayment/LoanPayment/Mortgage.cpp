#include "Mortgage.h"
#include<math.h>
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void Mortgage::setMonthlyPayment() {
	long double powerFactor;
	powerFactor = pow((1.0 + monthlyInterestRate), numberOfPayments);
	monthlyPayments = ((loanAmount * monthlyInterestRate * powerFactor) / (powerFactor - 1.0));
}
void Mortgage::setTotalPaid() {
	totalAmountPaid = monthlyPayments * numberOfPayments;
}
long double Mortgage::getloanAmount() const {
	return loanAmount;
}
long double Mortgage::getIRate() const {
	return monthlyInterestRate;
} 
long double Mortgage::getMonthlyPayment() const {
	return monthlyPayments;
}
long double Mortgage::getTotalPaid() const {
	return totalAmountPaid;
}

void Mortgage::outputPaymentSchedule(ofstream& outfile, string& filename) {
	long double contribution = getMonthlyPayment();
	long double remainingB = loanAmount;
	outfile.open(filename);
	while (outfile.fail()) {
		cout << "Failed to open file. Enter output file name: ";
		cin >> filename;

		outfile.open(filename);
	}

	outfile << "Loan Amount          : $" << getloanAmount() << endl
		<< "Annual Interest Rate : " << getIRate() << endl
		<< "Years to repay       : " << (numberOfPayments/12) << endl
		<< "Monthly Payment      : $" << getMonthlyPayment() << endl
		<< "Total Pay Back       : $" << getTotalPaid() << endl << endl;

	outfile << "Pmt#\t" << "Payment Amount\t" << "Interest\t" << "Contrib to principle\t" << "Remaining balance" << endl;

	for (int i = 0; remainingB > 0; i++) {
		outfile << fixed << setprecision(2) << right;
		outfile << i+1 << '\t' << getMonthlyPayment() << "\t\t"
			<< (remainingB * monthlyInterestRate) << "\t\t\t"
			<< (getMonthlyPayment() - (remainingB * monthlyInterestRate)) << "\t\t" // contribution to balance
			<< remainingB - (getMonthlyPayment() - (remainingB * monthlyInterestRate)) << endl; // balance minuse contrinbution

		contribution += getMonthlyPayment();
		remainingB -= (getMonthlyPayment() - (remainingB * monthlyInterestRate));
	}

	outfile.close();
}