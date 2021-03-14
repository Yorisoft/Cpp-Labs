cmake_minimum_required(VERSION 3.17)
project(BankAccounts
        VERSION 1.2
        DESCRIPTION Author:Yelsin,S)

set(CMAKE_CXX_STANDARD 14)

add_executable(BankAccounts main.cpp
        GenericAccount.h
        GenericAccount.cpp
        CheckingAccount.h
        CheckingAccount.cpp
        SavingsAccount.h
        SavingsAccount.cpp
        InactiveAccount.cpp
        InactiveAccount.h)