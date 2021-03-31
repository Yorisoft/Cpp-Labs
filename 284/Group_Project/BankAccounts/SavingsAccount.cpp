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
    if (this->GenericAccount<long double>::isActive()) {
        this->GenericAccount<long double>::withdraw(nWithdrawal);
    } else {
        throw InactiveAccount();
    }
}

void SavingsAccount::deposit(long double nDeposit) {
    long double tempBalance = this->GenericAccount<long double>::getBalance();

    if (this->GenericAccount<long double>::isActive() || ((tempBalance + nDeposit) >= 25)) { // proceed if active
        this->GenericAccount<long double>::deposit(nDeposit);
    } else {
        throw InactiveAccount();
    }
}

void SavingsAccount::monthlyProc() {
    int numOfWithdrawals = this->GenericAccount<int>::getNumOfWithdrawals();


    if (numOfWithdrawals > 4) {
        for (int y = 4; y < numOfWithdrawals; y++) {
            double tempServiceCharge = this->GenericAccount<double>::getServiceCharge();
            this->GenericAccount<double>::setServiceCharge((tempServiceCharge + 1));
        }
    }
    this->GenericAccount<long int>::monthlyProc();
}