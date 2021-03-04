// This is the implimentation file for GenericAccount.h class

#include "GenericAccount.h"
using namespace std;

// Constructors
GenericAccount::GenericAccount() {
	balance = 0;
	annualInterestRate = 0;
	numOfDeposites = 0;
	numOfWithdrawls = 0;
	serviceCharge = 0;
	monthlyOverdraft = 0.00;
	::GenericAccount(balance, annualInterestRate);
}
GenericAccount::GenericAccount(long double nbalance, double APR) {
	numOfDeposites = 0;
	numOfWithdrawls = 0;
	serviceCharge = 0;
	monthlyOverdraft = 0.00;
	this->setBalance(nbalance);
	this->setAnnualInterestRate(APR);
}

// Setters
void GenericAccount::setBalance(long double nbalance) {
	balance = nbalance;
}
void GenericAccount::setAnnualInterestRate(double APR) {
	annualInterestRate = APR;
}
void GenericAccount::setServerviceCharge(int nServiceCharge) {
	serviceCharge = nServiceCharge;
}
void GenericAccount::setMonthlyOverdraft(double overdraftAmount) {
	monthlyOverdraft = overdraftAmount;
}
void GenericAccount::setNumOfWithdrawls(int nNum) {
	numOfWithdrawls = nNum;
}

// Getters
int GenericAccount::getServiceCharge() {
	return serviceCharge;
}
int GenericAccount::getNumOfWithdrawls() {
	return numOfWithdrawls;
}
int GenericAccount::getNumOfDeposites() {
	return numOfDeposites;
}
double long GenericAccount::getBalance() {
	return balance;
}
double GenericAccount::getMonthlyOverdraft() {
	return monthlyOverdraft;
}


// Extra
bool GenericAccount::isActive() {
	balance < 25 ? accountStatus = false : accountStatus = true;
	return accountStatus;
}
void GenericAccount::deposit(long double ndeposit) {
	balance += ndeposit;
	numOfDeposites++;
}
void GenericAccount::withdraw(long double nwithdraw) {
	balance -= nwithdraw;
	numOfWithdrawls++;
}
void GenericAccount::calcInt() {
	double monthlyInterestRate = (annualInterestRate / 12);
	double monthlyInterest = (balance * monthlyInterestRate);
	balance += monthlyInterest;
}
void GenericAccount::monthlyProc() {
	balance -= serviceCharge;
	balance -= serviceCharge;
	this->calcInt();
	numOfDeposites = 0;
	numOfWithdrawls = 0;
	monthlyOverdraft = 0;
	accountStatus = isActive();
}