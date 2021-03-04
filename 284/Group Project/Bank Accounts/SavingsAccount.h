#ifndef SAVINGS_ACCOUNT
#define SAVINGS_ACCOUNT

#include "GenericAccount.h"
using namespace std;

class SavingsAccount : public GenericAccount {
private: 

public:
	//constructor
	SavingsAccount(long double nbalance, double APR);

	//setters

	//getters

	//extra
	void withdraw(long double nwithdraw) override;
	void deposit(long double ndeposit) override;
	void monthlyProc() override;
	
};
#endif