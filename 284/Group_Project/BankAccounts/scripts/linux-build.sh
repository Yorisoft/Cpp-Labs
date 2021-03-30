#!/bin/bash

cd 284/Group_Project/BankAccounts/
vendor/bin/premake/premake5 gmake2 config=deposit-fees-test
make 

#nmake -f Bootstrap.mak windows
