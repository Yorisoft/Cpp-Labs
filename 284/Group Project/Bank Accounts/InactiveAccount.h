#ifndef INACTIVE_ACCOUNT
#define INACTIVE_ACCOUNT

#include<string>
#include<iostream>
using namespace std;

class InactiveAccount
{
private:
	const string errorMsg = "Account is inactive..";

public:
	// Accessors
	const string getError() const;
};

#endif