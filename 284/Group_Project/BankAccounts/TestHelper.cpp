//
// Created by Yelsin S on 3/28/2021.
//
#define RESET   "\033[0m"
#define GREEN   "\033[32m"      /* Green */
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
    cout << GREEN << "\n Setting annual interest to " << annualInterestRate  << RESET << endl ;
    return annualInterestRate;
}

long double TestHelper::getStatingBalance() const {
    cout << GREEN << "\n Setting starting balance to " << startingBalance << RESET << endl ;
    return startingBalance;
}

long double TestHelper::getNewDeposit() {
    this->setNewDeposit();

    cout << GREEN << "\n Setting deposit to " << newDeposit << RESET << endl ;
    return newDeposit;
}

long double TestHelper::getNewWithdrawal() {
    this->setNewWithdrawal();
    cout << GREEN << "\n Setting withdrawal to " << newWithdrawal << RESET << endl ;
    return newWithdrawal;
}