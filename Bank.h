#pragma once

#include <iostream>
#include <vector>
#include "Account.h"

using namespace std;

class CBank {
private:
    vector<CAccount *> accountsP = {};
public:
    CBank() = default;

    ~CBank() = default;

    void addAcc(CAccount *account) { accountsP.push_back(account); }

    void printP();

    void print(const string &accountNum);

    void deposit(const string &accountNum, double amount);

    bool withdraw(const string &accountNum, double amount);

    bool transfer(const string &senderNum, const string &receiverNum, double amount);

//  int sizeP();
};