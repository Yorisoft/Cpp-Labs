//
// Created by Yelsin S on 3/28/2021.
//

#ifndef TEST_HELPER
#define TEST_HELPER

#include<vector>
using namespace std;
class TestHelper {

private:
    char testUserChoice;
    int numOfTransactions, accountToPrint;
    double annualInterestRate;
    long double startingBalance, newDeposit, newWithdrawal;


public:
//constructors
    TestHelper();

//setters
    void setNewDeposit();
    void setNewWithdrawal();

 //getters
    char getTestUserChoice();
    int getAccountToPrint();
    double getAPR() const;
    long double getStatingBalance() const;
    long double getNewDeposit();
    long double getNewWithdrawal();



};

#endif //TEST_HELPER

