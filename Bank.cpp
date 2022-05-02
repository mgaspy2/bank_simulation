#include <iostream>
#include "Bank.h"

void CBank::print() {
    for (auto &accountP: accountsP)
        accountP->print();
    cout << endl;
}

void CBank::print(const string &accountNum) {
    for (auto *accountP: accountsP) {
        if (accountP->ANum == accountNum) {
            accountP->print();
            cout << endl;
        }
    }
}

void CBank::deposit(const string &accountNum, double amount) {
    for (auto *accountP: accountsP) {
        if (accountP->ANum == accountNum){
            accountP->deposit(amount);
            break;
        }
    }
}

bool CBank::withdraw(const string &accountNum, double amount) {
    for (auto *accountP: accountsP)
        if (accountP->ANum == accountNum) return accountP->withdraw(amount);
    return false;
}

bool CBank::transfer(const string &senderNum, const string &receiverNum, double amount) {
    CAccount *sender = nullptr, *receiver = nullptr;

    for (auto *accountP: accountsP) {
        if (accountP->ANum == senderNum) sender = accountP;
        else if (accountP->ANum == receiverNum) receiver = accountP;
        if (sender && receiver) break;
    }
    if (sender == nullptr || receiver == nullptr) return false;
    return sender->transfer(receiver, amount);
}

void CBank::simulation(int days) {
    for(auto account:accountsP) {
        account->simulation(days);
    }
}

/*
int CBank::size() {
    int size = accountsP.size();
    return size;
}
*/
