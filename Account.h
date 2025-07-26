//Account class header file

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <bits/stdc++.h> 
using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    // constructor
    Account(int accNum, string name, double initialDeposit);

    // functions
    void deposit(double amount);
    bool withdraw(double amount);
    void displayAccountDetails() const;
    int getAccountNumber() const;
};

#endif
