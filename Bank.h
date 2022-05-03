#pragma once

#include <iostream>
#include <vector>
#include "Account.h"

using namespace std;

class CBank {
private:
    vector<CAccount *> accountsP = {};
    int rDays = 0;
public:
    CBank() = default;

    ~CBank() = default;

    void addAcc(CAccount *account) { accountsP.push_back(account); }

    void print();

    void print(const string &accountNum);

    void deposit(const string &accountNum, double amount);

    bool withdraw(const string &accountNum, double amount);

    bool transfer(const string &senderNum, const string &receiverNum, double amount);

    void tPrint();

    void simulation(int);

    void simulation();

    int size();
};

