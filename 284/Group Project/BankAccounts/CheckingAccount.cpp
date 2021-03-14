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

    long double tempBalance = GenericAccount<long double>::getBalance();

    if (GenericAccount<bool>::isActive() && ((tempBalance - nWithdraw) >= 0)) {
        GenericAccount<long double>::withdraw(nWithdraw);
    } else if ((tempBalance - nWithdraw) < 0) {
        cout << "Account was overcharged.. Withdrawal was canceled.." << endl << endl
             << "Account will be charged $15 for the overcharge.." << endl << endl;

        GenericAccount<long double>::setBalance((tempBalance - 15));

        GenericAccount<int>::setNumOfWithdrawals((GenericAccount<int>::getNumOfWithdrawals() + 1));
        GenericAccount<int>::setMonthlyOverdraft((GenericAccount<int>::getMonthlyOverdraft() + 15));
    } else {
        throw InactiveAccount();
    }
}

void CheckingAccount::monthlyProc() {
    int numOfDeposits = GenericAccount<int>::getNumOfDeposits();

    GenericAccount<double>::setServiceCharge((GenericAccount<double>::getServiceCharge() + 5));
    if (numOfDeposits > 4) {
        for (int y = 0; y < numOfDeposits; y++) {
            GenericAccount<double>::setServiceCharge(GenericAccount<double>::getServiceCharge() + 0.10);
        }
    }
    GenericAccount<long int>::monthlyProc();
}