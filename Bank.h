#pragma once

#include <iostream>
#include <vector>
#include "Account.h"

using namespace std;

class CBank {
private:
    vector<CAccount *> accountsP = {};                                            //vector of pointers on CAccount class objects     //vector of CAccount classes
public:
    CBank() = default;

    ~CBank() = default;

//	Pointer methods ======================================================================================
    void addAccP(CAccount* account) { accountsP.push_back(account); }

    void printP();

    void printP(string accountNum);

    void depositP(string accountNum, double amount);

    bool withdrawP(string accountNum, double amount);

    bool transferP(string senderNum, string receiverNum, double amount);

    int sizeP();
//  ======================================================================================================
};