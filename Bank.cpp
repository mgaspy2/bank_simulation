#include "Bank.h"
#include <iostream>


// Pointer methods ======================================================================================
void CBank::printP() {
    for (auto &accountP: accountsP)
        accountP->print();
    cout << endl;
}

void CBank::printP(string accountNum) {
    for (auto* accountP: accountsP) {
        if (accountP->ANum == accountNum) {
            accountP->print();
            cout << endl;
        }
    }
}

void CBank::depositP(const string accountNum, double amount) {
    for (auto* accountP: accountsP) {
        if (accountP->ANum == accountNum) accountP->deposit(amount);
        break;
    }
}

bool CBank::withdrawP(const string accountNum, double amount) {
    for (auto* accountP: accountsP)
        if (accountP->ANum == accountNum) return accountP->withdraw(amount);
    return false;
}

bool CBank::transferP(const string senderNum, const string receiverNum, double amount) {
    CAccount *sender = nullptr, *receiver = nullptr;

    for (auto* accountP: accountsP) {
        if (accountP->ANum == senderNum) sender = accountP;
        else if (accountP->ANum == receiverNum) receiver = accountP;
        if (sender && receiver) break;
    }
    if (sender == nullptr || receiver == nullptr) return false;
    return sender->transfer(receiver, amount);
}

int CBank::sizeP() {
    int s = accountsP.size();
    return s;
}
// ======================================================================================================
