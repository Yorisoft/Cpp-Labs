#ifndef SAVINGS_ACCOUNT
#define SAVINGS_ACCOUNT

#include "GenericAccount.h"

class SavingsAccount :
        public GenericAccount<long double>,
        public GenericAccount<long int>,
        public GenericAccount<double>,
        public GenericAccount<int>,
        public GenericAccount<bool> {
private:

public:
    //constructor
    SavingsAccount(long double nBalance, double APR);

    //setters

    //getters


//extra
    void withdraw(long double nWithdrawal);  //override;
    void deposit(long double nDeposit); // override;
    void monthlyProc();  //override;

};

#endif