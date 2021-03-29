//
// Created by Yelsin S on 3/28/2021.
//

#include "TestHelper.h"
#include<iostream>
#include<random>

using namespace std;


//constructors
TestHelper::TestHelper() :
    startingBalance(5000.00), annualInterestRate(0.08), numOfTransactions(0),
    accountToPrint(1), testUserChoice('N') {

}

//setters
void TestHelper::setNewDeposit() {
    newDeposit =  rand() % 599 + 15;
    newDeposit*= 1.5;
}

void TestHelper::setNewWithdrawal() {
    newWithdrawal =  rand() % 599 + 15;
    newWithdrawal*= 1.5;
}

//getters
char TestHelper::getTestUserChoice(){
    numOfTransactions <= 5 ? testUserChoice = 'Y' : testUserChoice = 'N';
    return testUserChoice;
}

int TestHelper::getAccountToPrint(){
    return accountToPrint;
}

double TestHelper::getAPR() const {
    cout << "\n Set annual interest to " << annualInterestRate << endl ;
    return annualInterestRate;
}

long double TestHelper::getStatingBalance() const {
    cout << "\n Set starting balance to " << startingBalance << endl ;
    return startingBalance;
}

long double TestHelper::getNewDeposit() {
    this->setNewDeposit();

    cout << "\n Set deposit to " << newDeposit << endl ;
    return newDeposit;
}

long double TestHelper::getNewWithdrawal() {
    this->setNewWithdrawal();
    cout << "\n Set withdrawal to " << newWithdrawal << endl ;
    return newWithdrawal;
}

int TestHelper::getNextTransaction() {
    int nextTransaction;

    if(numOfTransactions == 0 || numOfTransactions == 1) { //Deposit into Checking Account
        nextTransaction = 1;
        numOfTransactions+= 1;
    }
    if(numOfTransactions == 2 || numOfTransactions == 3) { //Withdraw from Checking Account
        nextTransaction = 2;
        numOfTransactions+= 1;
    }
    if(numOfTransactions == 4 || numOfTransactions == 5) { //Deposit into Checking Account
        nextTransaction = 1;
        numOfTransactions+= 1;
    }
    if(numOfTransactions == 6 || numOfTransactions == 7) { //Print out account
        nextTransaction = 5;
        numOfTransactions+= 1;
    }

    cout << "\n Set next transaction to " << nextTransaction << endl ;
    return nextTransaction;
}