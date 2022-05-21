#include <iostream>
#include <windows.h>
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
    for (auto *accountP: accountsP)
        if (accountP->ANum == accountNum) {
            accountP->deposit(amount);
            break;
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
    int Days = rDays + days;
    int months = 0;

    while (Days < 0) {
        Days += 30;
        months--;
    }
    while (months < 0) {
        months += 1;
    }
    months += Days / 30;
    Days %= 30;

    rDays = Days;
    cout << days << " days have passed ..." << endl << endl;
    for (auto account: accountsP) {
        account->simulation(months);
    }
    if (Days != 0) {
        if (rDays > 1)
            cout << rDays << " remainder days" << endl << endl;
        else
            cout << "1 remainder day" << endl << endl;
    }
    this->print();
}

void CBank::simulation() {
    int days = rDays;

    while (1) {
        Sleep(200);
        ++days;
        if (days > 29) {
            rDays = 0;
            this->simulation(days);
            days = 0;
        }
    }
}

int CBank::size() {
    int size = accountsP.size();
    return size;
}
