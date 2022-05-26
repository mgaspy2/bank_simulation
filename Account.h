#pragma once

#include <iostream>
#include "Currency.h"

using namespace std;

class CAccount {
protected:
    double ABal;
    string AName;
    string AType;
    currency_t ACurr;
    string pCurrency;

public:
    string ANum;

    CAccount();

    CAccount(string number, string name, currency_t currency, double balance = 0);

    ~CAccount() = default;

    virtual void print();

    void deposit(double);

    bool withdraw(double);

    bool transfer(CAccount *receiver, double amount);                   // method used by CBank methods

    bool transfer(CAccount &receiver, double amount);

    virtual void simulation(int) {}

//	void withdraw(double);												// old version
};

// SubClass Regular account ============================================================================================

class CARegular : public CAccount {
    double AMFee;

public:
    CARegular(string number, string name, currency_t currency, double fee, double balance = 0);

    ~CARegular() = default;

    void print() override;

    void simulation(int) override;
};

// SubClass Saving account =============================================================================================

class CASaving : public CAccount {
    double AIRate;
    int rMonths;

public:
    CASaving(string number, string name, currency_t currency, double iRate, double balance = 0);

    ~CASaving() = default;

    void print() override;

    void simulation(int) override;
};
