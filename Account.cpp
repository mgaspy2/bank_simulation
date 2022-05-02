#include <iostream>
#include "Account.h"
#include "Currency.h"

CAccount::CAccount() {
    AName = "";
    ANum = "";
    AType = "BASE";
    ACurr = EURO;
    pCurrency = " EURO";
    ABal = 0;
}

CAccount::CAccount(string number, string name, currency_t currency, double balance) {
    ANum = number;
    AName = name;
    ACurr = currency;
    ABal = balance;

    switch (this->ACurr) {
        case EURO:
            pCurrency = " EURO";
            break;
        case CZK:
            pCurrency = " CZK";
            break;
        case USD:
            pCurrency = " USD";
            break;
        case AUD:
            pCurrency = " AUD";
            break;
        default:
            pCurrency = " ---";
            break;
    }
}

void CAccount::print() {
    cout << "Number: " << ANum << ", " << "Name: " << AName << ", " << "Balance: " << ABal << pCurrency << endl;
}

void CAccount::deposit(double amount) {
    ABal += amount;
    cout << "Deposited " << amount << pCurrency << " to account num.: " << ANum << " ..." << endl;
    print();
    cout << endl;
}


bool CAccount::withdraw(double amount) {
    if (ABal < amount) {
        cout << "Insufficient funds, your balance is: " << ABal << " EUR" << endl << endl;
        return false;
    }
    ABal -= amount;
    cout << "Withdrawn " << amount << pCurrency << " from account num.: " << ANum << " ..." << endl;
    print();
    cout << endl;
    return true;
}

bool CAccount::transfer(CAccount *receiver, double amount) {
    double rate = 1.0;
    if (ABal < amount) {
        std::cout << "Insufficient funds, your balance is: " << ABal << pCurrency << endl << endl;
        return false;
    }
    if (receiver->ACurr != this->ACurr) {
        rate = exchangeRate(this->ACurr, receiver->ACurr);
    }
    ABal -= amount;
    receiver->ABal += amount * rate;
    cout << "Transferred " << amount << pCurrency << " from account num.: " << ANum << " to account num.: "
         << receiver->ANum
         << " ..." << endl;
    print();
    receiver->print();
    cout << endl;
    return true;
}

/*
void CAccount::withdraw(double value) {
    if (ABal > value) {
        ABal -= value;
        cout << "Withdrawn " << value << " EURO from account num.: " << ANum << " ..." << endl << endl;
    }
    else
        cout << "Insufficient funds, your balance is: " << ABal << " EUR" << endl << endl;
}
*/


// CARegular ======================================================================================================

CARegular::CARegular(string number, string name, currency_t currency, double fee, double balance) {
    ANum = number;
    AName = name;
    ACurr = currency;
    AType = "Regular";
    AMFee = fee;
    ABal = balance;

    switch (this->ACurr) {
        case EURO:
            pCurrency = " EURO";
            break;
        case CZK:
            pCurrency = " CZK";
            break;
        case USD:
            pCurrency = " USD";
            break;
        case AUD:
            pCurrency = " AUD";
            break;
        default:
            pCurrency = " ---";
            break;
    }
}

void CARegular::print() {
    cout << "Number: " << ANum << ", " << "Type: " << AType << ", " << "Name: " << AName << ", "
         << "Maintanance fee: " << AMFee << pCurrency << ", " << "Balance: " << ABal << pCurrency << endl;
}

void CARegular::simulation(int days) {
    int Days = days;
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

    for (int i = 0; i < months; ++i)
        ABal -= AMFee;
}


// CASaving =======================================================================================================

CASaving::CASaving(string number, string name, currency_t currency, double interest, double iRate, double balance) {
    ANum = number;
    AName = name;
    ACurr = currency;
    AType = "Saving";
    AInt = interest;
    AIRate = iRate;
    ABal = balance;

    switch (this->ACurr) {
        case EURO:
            pCurrency = " EURO";
            break;
        case CZK:
            pCurrency = " CZK";
            break;
        case USD:
            pCurrency = " USD";
            break;
        case AUD:
            pCurrency = " AUD";
            break;
        default:
            pCurrency = " ---";
            break;
    }
}

void CASaving::print() {
    cout << "Number: " << ANum << ", " << "Type: " << AType << ", " << "Name: " << AName << ", " << "Interest: "
         << AInt * 100 << " %" << ", " << "Interest rate: " << AIRate * 100 << " %" << ", " << "Balance: "
         << ABal << pCurrency << endl;
}

void CASaving::simulation(int days) {
    int Days = days;
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

    for (int i = 0; i < months; ++i) {
        ABal += ABal * AInt;
        ABal -= ABal * AIRate;
    }
}
