#include <bits/stdc++.h>
#include "Account.h"

using namespace std;

//functions
void createNewAccount(map<int, Account>& accounts);
Account* findAccount(map<int, Account>& accounts, int accNum);
void depositToAccount(map<int, Account>& accounts);
void withdrawFromAccount(map<int, Account>& accounts);
void checkAccountBalance(map<int, Account>& accounts);
void displayAllAccounts(const map<int, Account>& accounts);

int main() {
    // for random numbers
    srand(static_cast<unsigned int>(time(0)));

    map<int, Account> accounts;
    int choice;

    do {
        cout << "\n WELCOME TO HVA BANKS " << endl;
        cout << "1. Create a new account" << endl;
        cout << "2. Deposit money" << endl;
        cout << "3. Withdraw money" << endl;
        cout << "4. Check account balance" << endl;
        cout << "5. Display all accounts" << endl;
        cout << "6. Exit" << endl;
        cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter correct option." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                createNewAccount(accounts);
                break;
            case 2:
                depositToAccount(accounts);
                break;
            case 3:
                withdrawFromAccount(accounts);
                break;
            case 4:
                checkAccountBalance(accounts);
                break;
            case 5:
                displayAllAccounts(accounts);
                break;
            case 6:
                cout << "\nThank you for using HVA BANKS." << endl;
                break;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

void createNewAccount(map<int, Account>& accounts) {
    string name;
    double initialDeposit;

    cout << "\nEnter account holder's name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    cout << "Enter initial deposit amount: ";
    cin >> initialDeposit;

    if (cin.fail() || initialDeposit < 0) {
        cout << "Invalid deposit amount. Account creation failed." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    
    int newAccNum;

    // make a random account number
    do {
        newAccNum = 1000 + rand() % 9000; 
    } while (accounts.count(newAccNum));

    Account newAccount(newAccNum, name, initialDeposit);
    accounts.insert({newAccNum, newAccount});


    cout << "\nAccount created successfully!" << endl;
    cout << "Your Account Number is: " << newAccNum << endl;
}

Account* findAccount(map<int, Account>& accounts, int accNum) {
   auto it = accounts.find(accNum);
    if (it != accounts.end()) {
        return &it->second;
    }
         return nullptr;
}

void depositToAccount(map<int, Account>& accounts) {
    int accNum;
    double amount;

    cout << "\nEnter account number: ";
    cin >> accNum;

    Account* account = findAccount(accounts, accNum);

    if (account != nullptr) {
        cout << "Enter amount: ";
        cin >> amount;
        account->deposit(amount);
    } else {
        cout << "Account not found." << endl;
    }
}

void withdrawFromAccount(map<int, Account>& accounts) {
    int accNum;
    double amount;

    cout << "\nEnter account number to withdraw : ";
    cin >> accNum;

    Account* account = findAccount(accounts, accNum);

    if (account != nullptr) {
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        account->withdraw(amount);
    } else {
        cout << "Account not found." << endl;
    }
}

void checkAccountBalance(map<int, Account>& accounts) {
    int accNum;
    cout<<"\nBalance check";
    cout << "\nEnter account number: ";
    cin >> accNum;

    Account* account = findAccount(accounts, accNum);

    if (account != nullptr) {
        cout << "\nAccount Details" << endl;
        account->displayAccountDetails();
        cout << "X---------X" << endl;
    } else {
        cout << "Account not found." << endl;
    }
}

void displayAllAccounts(const map<int, Account>& accounts) {
    cout << "\n All Bank Accounts " << endl;
    if (accounts.empty()) {
        cout << "No accounts have been created yet." << endl;
    } else {
        for (const auto& pair : accounts) {
            pair.second.displayAccountDetails();
            }
    }
}
