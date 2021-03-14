// This is the implementation file for SavingsAccount.h class

#include "SavingsAccount.h"
#include "InactiveAccount.h"
#include "GenericAccount.cpp"

using namespace std;

// Constructor
SavingsAccount::SavingsAccount(long double nBalance, double APR)
        : GenericAccount<long double>::GenericAccount(nBalance, APR) {
    // ...
}

// Extras
void SavingsAccount::withdraw(long double nWithdrawal) {
    if (GenericAccount<bool>::isActive()) {
        GenericAccount<long double>::withdraw(nWithdrawal);
    } else {
        throw InactiveAccount();
    }
}

void SavingsAccount::deposit(long double nDeposit) {
    long double tempBalance = GenericAccount<long double>::getBalance();

    if (GenericAccount<bool>::isActive() || ((tempBalance + nDeposit) >= 25)) { // proceed if active
        GenericAccount<long double>::deposit(nDeposit);
    } else {
        throw InactiveAccount();
    }
}

void SavingsAccount::monthlyProc() {
    int numOfWithdrawals = GenericAccount<int>::getNumOfWithdrawals();


    if (numOfWithdrawals > 4) {
        for (int y = 4; y < numOfWithdrawals; y++) {
            double tempServiceCharge = GenericAccount<double>::getServiceCharge();
            GenericAccount<double>::setServiceCharge((tempServiceCharge + 1));
        }
    }
    GenericAccount<long int>::monthlyProc();
}