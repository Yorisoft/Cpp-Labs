#!/bin/bash

cd 284/Group_Project/BankAccounts/
vendor/bin/premake/premake5 gmake2
make config=deposit-fees-test -f Bootstrap.mak linux

#nmake -f Bootstrap.mak windows
