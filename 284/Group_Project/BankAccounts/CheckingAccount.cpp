// This is the implementation file for SavingsAccount.h class
#include<iostream>
#include "CheckingAccount.h"
#include "InactiveAccount.h"
#include "GenericAccount.h"
#include "GenericAccount.cpp"

using namespace std;

// Constructor
CheckingAccount::CheckingAccount(long double nBalance, double nAnnualInterest)
        : GenericAccount<long double>::GenericAccount(nBalance, nAnnualInterest) {
    // ...
}

// Extra
void CheckingAccount::withdraw(long double nWithdraw) {

    long double tempBalance = this->GenericAccount<long double>::getBalance();

    if (this->GenericAccount<long double>::isActive() && ((tempBalance - nWithdraw) >= 0)) {
        this->GenericAccount<long double>::withdraw(nWithdraw);
        this->GenericAccount<int>::setNumOfWithdrawals(this->GenericAccount<int>::getNumOfWithdrawals() + 1);
    } else if ((tempBalance - nWithdraw) < 0) {
        cout << "Account was overcharged.. Withdrawal was canceled.." << endl << endl
             << "Account will be charged $15 for the overcharge.." << endl << endl;

        this->GenericAccount<long double>::setBalance((tempBalance - 15));

        this->GenericAccount<int>::setNumOfWithdrawals((this->GenericAccount<int>::getNumOfWithdrawals() + 1));
        this->GenericAccount<int>::setMonthlyOverdraft((this->GenericAccount<int>::getMonthlyOverdraft() + 15));
        throw InactiveAccount();
    }
}

void CheckingAccount::deposit(long double nDeposit){
    this->GenericAccount<long double>::deposit(nDeposit);
    this->GenericAccount<int>::setNumOfDeposits(this->GenericAccount<int>::getNumOfDeposits() + 1);
}

void CheckingAccount::monthlyProc() {
    int numOfDeposits = this->GenericAccount<int>::getNumOfDeposits();

    this->GenericAccount<double>::setServiceCharge((this->GenericAccount<double>::getServiceCharge() + 5));
    if (numOfDeposits > 4) {
        for (int y = 0; y < numOfDeposits; y++) {
            this->GenericAccount<double>::setServiceCharge(this->GenericAccount<double>::getServiceCharge() + 0.10);
        }
    }
    this->GenericAccount<long double>::monthlyProc();
}