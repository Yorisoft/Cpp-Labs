// This is the implimentation file for SavingsAccount.h class

#include<iostream>
#include "CheckingsAccount.h"
#include "InactiveAccount.h"
using namespace std;

// Contructor
CheckingsAccount::CheckingsAccount(double long nBalance, double nAnnualInterest)
	: GenericAccount (nBalance, nAnnualInterest){

}

// Extra
void CheckingsAccount::withdraw(long double nWithdraw) {
	long double tempBalance = this->getBalance();

		if (this->isActive() && ((tempBalance - nWithdraw) >= 0)) {
			GenericAccount::withdraw(nWithdraw);
		}
		else if ((tempBalance - nWithdraw) < 0) {
			cout << "Account was overcharged.. Withdrawl was canceled.." << endl << endl
				<< "Account will be charged $15 for the overcharge.." << endl << endl;

			this->setBalance((tempBalance - 15));

			this->setNumOfWithdrawls((this->getNumOfWithdrawls() + 1));
			this->setMonthlyOverdraft((this->getMonthlyOverdraft() + 15));

			
		}
		else {
			throw InactiveAccount();
		}
}
void CheckingsAccount::monthlyProc() {
	int numOfDeposites = this->getNumOfDeposites();

	this->setServerviceCharge((this->getServiceCharge() + 5));
	if (numOfDeposites > 4) {
		for (int y = 0; y < numOfDeposites; y++) {
			this->setServerviceCharge(this->getServiceCharge() + 0.10);
		}
	}
	GenericAccount::monthlyProc();
}