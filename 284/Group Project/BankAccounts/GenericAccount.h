#ifndef GENERIC_ACCOUNT
#define GENERIC_ACCOUNT
using namespace std;

template<class T>
class GenericAccount {
private:
    T annualInterestRate, serviceCharge, monthlyOverdraft, // double
    balance, // long double
    numOfWithdrawals, numOfDeposits; // int
    bool accountStatus;

public:
    //constructors
    GenericAccount();
    GenericAccount(T nBalance, T APR);

    //setters
    void setBalance(T nBalance);
    void setAnnualInterestRate(T APR);
    void setServiceCharge(T nServiceCharge);
    void setMonthlyOverdraft(T overdraftAmount);
    void setNumOfWithdrawals(T nNum);

    //getters
    T getNumOfWithdrawals() const;
    T getNumOfDeposits() const;
    T getServiceCharge() const;
    T getBalance() const;
    T getMonthlyOverdraft() const;
    T getAPR() const;

    //extra
    bool isActive();
    void deposit(T nDeposit);
    void withdraw(T nWithdraw);
    void calcInt();
    void monthlyProc();
};

#endif