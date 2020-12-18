#ifndef MORTGAGE_H
#define MORTGAGE_H
#include<string>
using namespace std;

class Mortgage {
private:
	long double loanAmount, monthlyInterestRate, 
		monthlyPayments, annualInterestRate, 
		totalAmountPaid,numberOfPayments;

public:
	void setLoanAmount(long double amount) 
		{loanAmount = amount;}
	void setMonthlyInterestRate(long double iRate)
		{monthlyInterestRate = iRate/12;}
	void setNumberOfPayments(double years) 
		{numberOfPayments = years*12;}
	void setMonthlyPayment();
	void setTotalPaid();

	long double getloanAmount() const;
	long double getIRate() const;
	long double getMonthlyPayment() const;
	long double getTotalPaid() const;

	void outputPaymentSchedule(ofstream& outfile, string& filename);
};
#endif