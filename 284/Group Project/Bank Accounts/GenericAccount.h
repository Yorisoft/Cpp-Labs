#ifndef GENERIC_ACCOUNT
#define GENERIC_ACCOUNT

using namespace std;

class GenericAccount {
private:
	double annualInterestRate, serviceCharge, monthlyOverdraft;
	long double balance;
	int numOfWithdrawls, numOfDeposites;
	bool accountStatus;

public:
	//constructors
	GenericAccount();
	GenericAccount(long double nbalance, double APR);

	//setters
	void setBalance(long double nbalance);
	void setAnnualInterestRate(double APR);
	void setServerviceCharge(int nServiceCharge);
	void setMonthlyOverdraft(double overdraftAmount);
	void setNumOfWithdrawls(int nNum);

	//getters
	int getNumOfWithdrawls();
	int getNumOfDeposites();
	int getServiceCharge();
	double long getBalance();
	double getMonthlyOverdraft();

	//extra
	bool isActive();
	virtual void deposit(long double ndeposit);
	virtual void withdraw(long double nwithdraw);
	virtual void calcInt();
	virtual void monthlyProc();

};

#endif