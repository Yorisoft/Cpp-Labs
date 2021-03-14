// This is the implementation file for InactiveAccount.h class
#include<string>
#include<iostream>
#include "InactiveAccount.h"

using namespace std;


// Accessors
string InactiveAccount::getError() const {
    return errorMsg;
}