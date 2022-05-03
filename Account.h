#pragma once

#include <iostream>
#include "Currency.h"

using namespace std;

class CAccount {
public:
    string AName;
    string ANum;
    string AType;
    double ABal;
    currency_t ACurr;
    string pCurrency;

    CAccount();

    CAccount(string number, string name, currency_t currency, double balance = 0);

    ~CAccount() = default;

    virtual void print();

    void deposit(double);

    bool withdraw(double);

    bool transfer(CAccount *receiver, double amount);

    bool transfer(CAccount receiver, double amount);

    virtual void simulation(int) {}

//	void withdraw(double);												//old version
};

//SubClass Regular account =============================================================================================

class CARegular : public CAccount {
public:
    string AType;
    double AMFee;

    CARegular(string number, string name, currency_t currency, double fee, double balance = 0);

    ~CARegular() = default;

    void print() override;

    void simulation(int) override;
};

//SubClass Saving account ==============================================================================================

class CASaving : public CAccount {
public:
    string AType;
    double AInt;
    double AIRate;
    int rMonths;

    CASaving(string number, string name, currency_t currency, double interest, double iRate, double balance = 0);

    ~CASaving() = default;

    void print() override;

    void simulation(int) override;
};
