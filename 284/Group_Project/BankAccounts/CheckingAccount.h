#ifndef CHECKING_ACCOUNT
#define CHECKING_ACCOUNT

#include "GenericAccount.h"

using namespace std;

class CheckingAccount :
        public GenericAccount<CheckingAccount *>,
        public GenericAccount<long double>,
        public GenericAccount<long int>,
        public GenericAccount<double>,
        public GenericAccount<int>,
        public GenericAccount<bool> {
private:

public:
    //constructor
    CheckingAccount(long double nBalance, double nAnnualInterest);

    //extra
    void withdraw(long double nWithdraw);//
    void deposit(long double nDeposit);//
    void monthlyProc(); //

};

#endif