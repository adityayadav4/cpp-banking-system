// function for Account class

#include "Account.h"

// contructor
Account::Account(int accNum, string name, double initialDeposit) {
    accountNumber = accNum;
    accountHolderName = name;
    balance = initialDeposit;
}

// function to deposit money 
void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "\nDeposit successful. Current balance : " << fixed << setprecision(2) << balance << endl;
    } else {
        cout << "\nInvalid amount. Please enter valid amount." << endl;
    }
}

// function for withdrawl
bool Account::withdraw(double amount) {
    if (amount <= 0) {
        cout << "\nInvalid amount. Please enter valid amount." << endl;
        return false;
    }
    
    if (amount > balance) {
        cout << "\nInsufficient balance." << endl;
        return false;
    }

    balance -= amount;
    cout << "\nWithdrawal successful. Current balance : " << fixed << setprecision(2) << balance << endl;
    return true;
}

// shows account details
void Account::displayAccountDetails() const {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account Holder: " << accountHolderName << endl;
    cout << "Balance: " << fixed << setprecision(2) << balance << endl;
}

// return account number
int Account::getAccountNumber() const {
    return accountNumber;
}
