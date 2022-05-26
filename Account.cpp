#include <iostream>
#include <iomanip>
#include "Account.h"
#include "Currency.h"

CAccount::CAccount() {
    AName = "";
    ANum = "";
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
    cout << "Number: " << ANum << ", Name: " << AName << ", Balance: " << setprecision(2) << fixed << ABal
         << pCurrency << endl;
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
        cout << "Insufficient funds, your balance is: " << ABal << pCurrency << endl << endl;
        return false;
    }
    if (receiver->ACurr != this->ACurr) {
        rate = exchangeRate(this->ACurr, receiver->ACurr);
    }
    ABal -= amount;
    receiver->ABal += amount * rate;
    cout << "Transferred " << amount << pCurrency << " from account num.: " << ANum << " to account num.: "
         << receiver->ANum << " ..." << endl;
    print();
    receiver->print();
    cout << endl;
    return true;
}

bool CAccount::transfer(CAccount &receiver, double amount) {
    double rate = 1.0;
    if (ABal < amount) {
        cout << "Insufficient funds, your balance is: " << ABal << pCurrency << endl << endl;
        return false;
    }
    if (receiver.ACurr != ACurr) {
        rate = exchangeRate(ACurr, receiver.ACurr);
    }
    ABal -= amount;
    receiver.ABal += amount * rate;
    cout << "Transferred " << amount << pCurrency << " from account num.: " << ANum << " to account num.: "
         << receiver.ANum << " ..." << endl;
    print();
    receiver.print();
    cout << endl;
    return true;
}

/*
void CAccount::withdraw(double amount) {
    if (ABal > amount) {
        ABal -= amount;
        cout << "Withdrawn " << amount << " EURO from account num.: " << ANum << " ..." << endl << endl;
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
    cout << "Number: " << ANum << ", Type: " << AType << ", Name: " << AName
         << ", Maintenance fee: " << AMFee << pCurrency << ", Balance: " << setprecision(2) << fixed << ABal
         << pCurrency << endl;
}

void CARegular::simulation(int months) {
    for (int i = 0; i < months; ++i)
        ABal -= AMFee;
}

// CASaving =======================================================================================================

CASaving::CASaving(string number, string name, currency_t currency, double iRate, double balance) {
    ANum = number;
    AName = name;
    ACurr = currency;
    AType = "Saving";
    AIRate = iRate;
    ABal = balance;
    rMonths = 0;

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
    cout << "Number: " << ANum << ", Type: " << AType << ", Name: " << AName << ", Interest rate: " << AIRate * 100
         << " %, Balance: " << setprecision(2) << fixed << ABal << pCurrency << endl;
}

void CASaving::simulation(int Months) {
    int months = rMonths + Months;
    int years = 0;

    while (months < 0) {
        months += 12;
        years--;
    }
    while (years < 0) {
        years += 1;
    }
    years += months / 12;
    months %= 12;

    rMonths = months;
    if (years > 0) {
        for (int i = 0; i < years; ++i) {
            ABal += ABal * AIRate;
        }
    } else {
        if (rMonths > 1)
            cout << rMonths << " remainder months" << endl << endl;
        else
            cout << "1 remainder month" << endl << endl;
    }

}
