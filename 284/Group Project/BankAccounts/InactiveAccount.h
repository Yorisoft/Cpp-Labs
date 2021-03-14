#ifndef INACTIVE_ACCOUNT
#define INACTIVE_ACCOUNT

#include<string>
#include<iostream>

using namespace std;

class InactiveAccount : public exception {
private:
    const string errorMsg = "Account is inactive..";

public:
    // Accessors
    string getError() const;
};

#endif