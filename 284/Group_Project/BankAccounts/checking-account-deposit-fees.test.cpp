// Bank Accounts - Project 1 
// This program uses three classes to emulate a Savings and Checking account.
// Prof Carmelito Moreno - CSC 284-H1
// Yelsin Sepulveda
#define RESET   "\033[0m"
#define GREEN   "\033[32m"      /* Green */

#include<cstdlib>
#include<iostream>
#include<string>
#include <iomanip>
#include<vector>
#include "TestHelper.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "InactiveAccount.h"
#include "GenericAccount.cpp"
using namespace std;

void printBanner();
void printInterface();
int getValidTransaction(string ENV_VARIABLE, TestHelper* TestHelperPtr, int &counter);
void savingDeposit(SavingsAccount *nSavingsAccountPtr, string ENV_VARIABLE, TestHelper* TestHelperPtr);
void savingWithdrawal(SavingsAccount *nSavingsAccountPtr, string ENV_VARIABLE, TestHelper* TestHelperPtr);
void checkingDeposit(CheckingAccount *nCheckingAccountPtr, string ENV_VARIABLE, TestHelper* TestHelperPtr);
void checkingWithdrawal(CheckingAccount *nCheckingAccountPtr, string ENV_VARIABLE, TestHelper* TestHelperPtr);
void printEndOfMonth(CheckingAccount *nCheckingAccountPtr, SavingsAccount *nSavingsAccountPtr,
                     long double &startingCheckingBalance, long double &startingSavingBalance,
                     string ENV_VARIABLE, TestHelper* TestHelperPtr);

int main() {
    // TEST VARIABLES
    const string ENV_VARIABLE = getenv("CPP_TEST_ENV");
    auto *TestHelperPtr = new TestHelper();
    int counter = 0;

    // VARIABLES
    string choice = "yes";
    int transaction;
    double APR;
    long double startingCheckingBalance, startingSavingBalance;
    CheckingAccount *CheckingAccountPtr = nullptr;
    SavingsAccount *SavingsAccountPtr = nullptr;


    printBanner();

    // COLLECT USER STARTING CHECKING BALANCE
    cout << "What would you like as your starting balance for your Checking account ?? "
            "( Minimum of $25 to activate account)  ";
    if (ENV_VARIABLE != "jenkins"){
        cin >> startingCheckingBalance;
        cin.ignore(100, '\n');
    } else {
        startingCheckingBalance = TestHelperPtr->getStatingBalance();
    }

    // COLLECT USER STARTING SAVING BALANCE
    cout << "What would you like as your starting balance for your Savings account ?? "
            "( Minimum of $25 to activate account)  ";
    if (ENV_VARIABLE != "jenkins"){
        cin >> startingSavingBalance;
        cin.ignore(100, '\n');
    } else {
        startingSavingBalance = TestHelperPtr->getStatingBalance();
    }

    // COLLECT USER APR VALUE
    cout << "What is the annual interest rate for your Savings account?? ";
    if (ENV_VARIABLE != "jenkins"){
        cin >> APR;
        cin.ignore(100, '\n');
    } else {
        APR = TestHelperPtr->getAPR();
    }

    // Initializing new checking and savings account object
    CheckingAccountPtr = new CheckingAccount(startingCheckingBalance, APR);
    SavingsAccountPtr = new SavingsAccount(startingSavingBalance, APR);

    while (choice[0] == 'y' || choice[0] == 'Y') {
        try {
            printInterface();
            transaction = getValidTransaction(ENV_VARIABLE, TestHelperPtr, counter);

            switch (transaction) {
                case 1:
                    checkingDeposit(CheckingAccountPtr, ENV_VARIABLE, TestHelperPtr);
                    cout << "New Checking Balance: " << CheckingAccountPtr->GenericAccount<long double>::getBalance()
                         << endl << endl;
                    break;
                case 2:
                    checkingWithdrawal(CheckingAccountPtr, ENV_VARIABLE, TestHelperPtr);
                    cout << "New Checking Balance: " << CheckingAccountPtr->GenericAccount<long double>::getBalance()
                         << endl << endl;
                    break;
                case 3:
                    savingDeposit(SavingsAccountPtr, ENV_VARIABLE, TestHelperPtr);
                    cout << "New Saving Balance: " << SavingsAccountPtr->GenericAccount<long double>::getBalance()
                         << endl << endl;
                    break;
                case 4:
                    savingWithdrawal(SavingsAccountPtr, ENV_VARIABLE, TestHelperPtr);
                    cout << "New Saving Balance: " << SavingsAccountPtr->GenericAccount<long double>::getBalance()
                         << endl << endl;
                    break;
                case 5:
                    printEndOfMonth(CheckingAccountPtr, SavingsAccountPtr, startingCheckingBalance,
                                    startingSavingBalance, ENV_VARIABLE, TestHelperPtr);
                    break;
                default:
                    cout << "Invalid selection.. Try again.." << endl << endl;
                    break;
            }
        }
        catch (InactiveAccount &e) {
            cout << "Coule not Complete transaction " << endl
                 << '\t' << e.getError() << endl;
        }

        cout << "Would you like to enter another transaction ? [Y/n] ";
        if (ENV_VARIABLE != "jenkins") {
            cin >> choice; cin.ignore(100, '\n');
        } else {
            counter >= 6 ? choice = 'N' : choice = 'Y';
            counter++;
        }
    }

    delete CheckingAccountPtr;
    delete SavingsAccountPtr;
    delete TestHelperPtr;

    if (ENV_VARIABLE != "jenkins"){
        system("PAUSE");
        return 0;
    } else {
        return 0;
    }
}

void printBanner() {
    cout << "\t\t        This program emulates the functionality of both a Checking       " << endl
         << "\t\t && Savings bank account, then prints out an End-Of-Month review message " << endl << endl;
}

void printInterface() {
    cout << "Select one of these options: " << endl
         << '\t' << "1. Deposit into Checking Account " << endl
         << '\t' << "2. Withdraw from Checking Account " << endl
         << '\t' << "3. Deposit into Savings Account " << endl
         << '\t' << "4. Withdraw from Savings Account " << endl
         << '\t' << "5. Print out End-Of-Month review message " << endl << endl;
}

int getValidTransaction(string ENV_VARIABLE, TestHelper* TestHelperPtr, int &counter) {
    int usrInput;

    // Checking Deposit fee workflow
    vector<int> workflowChoices = {1, 1, 1, 1, 1, 1, 5};
    
    cout << "What transaction would you like to perform ? (1 - 5) ";
    if (ENV_VARIABLE != "jenkins"){
        cin >> usrInput;
    } else {
        cout << GREEN << "\n Setting next transaction to " << workflowChoices[counter]
            << RESET << endl;
        usrInput = workflowChoices[counter];
        return usrInput;
    }

    while ((isdigit(usrInput) || usrInput < 1 || usrInput > 5)) {
        cout << "Please enter an integer 1 - 5:";
        cin >> usrInput;
    }
    return usrInput;
}

void checkingDeposit(CheckingAccount *nCheckingAccountPtr, string ENV_VARIABLE, TestHelper* TestHelperPtr) {
    long double newDeposit;

    cout << "How much would you like to deposit into your checking account ? ";

    if (ENV_VARIABLE != "jenkins"){
        cin >> newDeposit; cin.ignore(100, '\n');
    } else {
        newDeposit = TestHelperPtr->getNewDeposit();
    }

    nCheckingAccountPtr->deposit(newDeposit);
    cout << "Finished transaction.." << endl;
}

void checkingWithdrawal(CheckingAccount *nCheckingAccountPtr, string ENV_VARIABLE, TestHelper* TestHelperPtr) {
    long double newWithdrawal;

    try {
        cout << "How much would you like to withdraw from your checking account ? ";
        if (ENV_VARIABLE != "jenkins"){
            cin >> newWithdrawal; cin.ignore(100, '\n');
        } else {
            newWithdrawal = TestHelperPtr->getNewWithdrawal();
        }

        nCheckingAccountPtr->withdraw(newWithdrawal);
        cout << "Finished transaction.." << endl;
    }
    catch (InactiveAccount &e) {
        throw e;
    }

}

void savingDeposit(SavingsAccount *nSavingsAccountPtr, string ENV_VARIABLE, TestHelper* TestHelperPtr) {
    long double newDeposit;

    try {
        cout << "How much would you like to deposit into your savings account ? ";

        if (ENV_VARIABLE != "jenkins"){
            cin >> newDeposit; cin.ignore(100, '\n');
        } else {
            newDeposit = TestHelperPtr->getNewDeposit();
        }

        nSavingsAccountPtr->deposit(newDeposit);
        cout << "Finished transaction.." << endl;
    }
    catch (InactiveAccount &e) {
        throw e;
    }
}

void savingWithdrawal(SavingsAccount *nSavingsAccountPtr, string ENV_VARIABLE, TestHelper* TestHelperPtr) {
    long double newWithdrawal;

    try {
        cout << "How much would you like to withdraw from your savings account ? ";
        if (ENV_VARIABLE != "jenkins"){
            cin >> newWithdrawal; cin.ignore(100, '\n');
        } else {
            newWithdrawal = TestHelperPtr->getNewWithdrawal();
        }

        nSavingsAccountPtr->withdraw(newWithdrawal);
        cout << "Finished transaction.." << endl;
    }
    catch (InactiveAccount &e) {
        throw e;
    }
}

void printEndOfMonth(CheckingAccount *nCheckingAccountPtr, SavingsAccount *nSavingsAccountPtr,
                     long double &startingCheckingBalance, long double &startingSavingBalance,
                     string ENV_VARIABLE, TestHelper* TestHelperPtr) {
    cout << setprecision(2) << fixed;
    int accountChosen;

    cout << "What account would you like to print?" << endl
         << "1. Checking " << endl
         << "2. Savings " << endl;

    if (ENV_VARIABLE != "jenkins") {
        cin >> accountChosen; cin.ignore(100, '\n');
    } else {
        accountChosen = TestHelperPtr->getAccountToPrint();
    }

    if (accountChosen == 1) {
        // Checking
        cout << "This is your end of month review: " << endl
             << "\t" << "Checking Account: " << endl
             << "\t\t" << "Starting Balance: " << startingCheckingBalance << endl
             << "\t\t" << "Total Num. of deposits: " << nCheckingAccountPtr->GenericAccount<int>::getNumOfDeposits() << endl
             << "\t\t" << "Total Num. of withdrawals: "
             << nCheckingAccountPtr->GenericAccount<int>::getNumOfWithdrawals() << endl;
        nCheckingAccountPtr->monthlyProc();
        cout << "\t\t" << "Service Fees:       -" << nCheckingAccountPtr->GenericAccount<double>::getServiceCharge() << endl
             << "\t\t" << "Monthly Overdrafts: -" << nCheckingAccountPtr->GenericAccount<double>::getMonthlyOverdraft() << endl
             << "\t\t" << "Total in Fees and Overdraft: -"
             << (nCheckingAccountPtr->GenericAccount<double>::getServiceCharge()
                 + nCheckingAccountPtr->GenericAccount<double>::getMonthlyOverdraft()) << endl
             << "\t\t" << "Ending Balance: " << nCheckingAccountPtr->GenericAccount<long double>::getBalance() << endl << endl;
    } else {
        // Savings
        cout << "\t" << "Savings Account: " << endl
             << "\t\t" << "Starting Balance: " << startingSavingBalance << endl
             << "\t\t" << "Total Num. of deposits: " << nSavingsAccountPtr->GenericAccount<int>::getNumOfDeposits() << endl
             << "\t\t" << "Total Num. of withdrawals: " << nSavingsAccountPtr->GenericAccount<int>::getNumOfWithdrawals() << endl;
        nSavingsAccountPtr->monthlyProc();
        cout << "\t\t" << "Service Fees:      " << nSavingsAccountPtr->GenericAccount<double>::getServiceCharge() << endl
             << "\t\t" << "Monthly Overdrafts: " << nSavingsAccountPtr->GenericAccount<double>::getMonthlyOverdraft() << endl
             << "\t\t" << "Total in Fees and Overdraft: "
             << (nSavingsAccountPtr->GenericAccount<double>::getServiceCharge()
                 + nSavingsAccountPtr->GenericAccount<double>::getMonthlyOverdraft()) << endl
             << "\t\t" << "Ending Balance: " << nSavingsAccountPtr->GenericAccount<long double>::getBalance() << endl << endl;
    }
}