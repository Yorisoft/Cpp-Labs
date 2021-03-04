#ifndef CHECKINGS_ACCOUNT
#define CHECKINGS_ACCOUNT

#include "GenericAccount.h"
using namespace std;

class CheckingsAccount : public GenericAccount {
private:

public:
	//constructor
	CheckingsAccount(double long nBalance, double nAnnualInterest);

	//extra
	void monthlyProc() override;
	void withdraw(long double nWithdraw) override;

};

#endif