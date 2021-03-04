// This is the implimentation file for SavingsAccount.h class

#include<iostream>
#include "SavingsAccount.h"
#include "InactiveAccount.h"
using namespace std;

// Constructor
SavingsAccount::SavingsAccount(long double nbalance, double APR)
	: GenericAccount(nbalance, APR) {
	// ...
}

// Extras
void SavingsAccount::withdraw(long double nwithdraw) {
	if (this->isActive()) {
		GenericAccount::withdraw(nwithdraw);
	}
	else {
		throw InactiveAccount();
	}
}
void SavingsAccount::deposit(long double ndeposit) {
	long double tempBalance = this->getBalance();

	if (this->isActive() || ((tempBalance + ndeposit) >= 25)) { // proceed if active
		GenericAccount::deposit(ndeposit);
	}
	else {
		throw InactiveAccount();
	}
}
void SavingsAccount::monthlyProc(){
	int numOfWithdrawls = this->getNumOfWithdrawls();

	
	if (numOfWithdrawls > 4) {
		for (int y = 4; y < numOfWithdrawls; y++) {
			double tempServiceCharge = this->getServiceCharge();
			this->setServerviceCharge((tempServiceCharge + 1));
		}
	}
	GenericAccount::monthlyProc();
}