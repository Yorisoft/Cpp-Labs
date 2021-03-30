#!/bin/bash

cd 284/Group_Project/BankAccounts/
vendor/bin/premake/premake5 gmake2
make config=deposit-fees-test

#nmake -f Bootstrap.mak windows
