// This is the implementation file for GenericAccount.h class

#include "GenericAccount.h"
using namespace std;

// Constructors
//template <class T>
//GenericAccount<T>::GenericAccount()
//: annualInterestRate(this->getAPR()), serviceCharge(0), monthlyOverdraft(0),
//  balance(this->getBalance()), numOfWithdrawals(0), numOfDeposits(0),
//  accountStatus(this->isActive()) {
//    // ...
//}

template<class T>
GenericAccount<T>::GenericAccount() {

}

template<class T>
GenericAccount<T>::GenericAccount(T nBalance, T APR)
        : serviceCharge(0), monthlyOverdraft(0), numOfWithdrawals(0),
          numOfDeposits(0) {

    setBalance(nBalance);
    setAnnualInterestRate(APR);
    accountStatus = isActive();

}

// Setters
template<class T>
void GenericAccount<T>::setBalance(T nBalance) {
    balance = nBalance;
}

template<class T>
void GenericAccount<T>::setAnnualInterestRate(T APR) {
    annualInterestRate = APR;
}

template<class T>
void GenericAccount<T>::setServiceCharge(T nServiceCharge) {
    serviceCharge = nServiceCharge;
}

template<class T>
void GenericAccount<T>::setMonthlyOverdraft(T overdraftAmount) {
    monthlyOverdraft = overdraftAmount;
}

template<class T>
void GenericAccount<T>::setNumOfDeposits(T nNum) {
    numOfDeposits = nNum;
}

template<class T>
void GenericAccount<T>::setNumOfWithdrawals(T nNum) {
    numOfWithdrawals = nNum;
}

// Getters
template<class T>
T GenericAccount<T>::getServiceCharge() const {
    return serviceCharge;
}

template<class T>
T GenericAccount<T>::getNumOfWithdrawals() const {
    return numOfWithdrawals;
}

template<class T>
T GenericAccount<T>::getNumOfDeposits() const {
    return numOfDeposits;
}

template<class T>
T GenericAccount<T>::getBalance() const {
    return balance;
}

template<class T>
T GenericAccount<T>::getMonthlyOverdraft() const {
    return monthlyOverdraft;
}

template<class T>
T GenericAccount<T>::getAPR() const {
    return annualInterestRate;
}

// Extra
template<typename T>
bool GenericAccount<T>::isActive() {
    balance < 25 ? accountStatus = false : accountStatus = true;
    return accountStatus;
}

template<class T>
void GenericAccount<T>::deposit(T nDeposit) {
    balance += nDeposit;
}

template<class T>
void GenericAccount<T>::withdraw(T nWithdraw) {
    balance -= nWithdraw;
}

template<class T>
void GenericAccount<T>::calcInt() {
    double monthlyInterestRate = (annualInterestRate / 12);
    long double monthlyInterest = (balance * monthlyInterestRate);
    balance += monthlyInterest;
}

template<class T>
void GenericAccount<T>::monthlyProc() {
    balance -= serviceCharge;
    calcInt();
    numOfDeposits = 0;
    numOfWithdrawals = 0;
    monthlyOverdraft = 0;
    accountStatus = isActive();
}

