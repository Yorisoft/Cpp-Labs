// This is the implimentation file for InactiveAccount.h class
#include<string>
#include<iostream>
#include "InactiveAccount.h"
using namespace std;


// Accessors
const string InactiveAccount::getError() const {
	return errorMsg;
}