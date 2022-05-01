#include "Account.h"
#include "Currency.h"
#include <iostream>

CAccount::CAccount(string number, string name, currency_t currency, double balance) {
    ANum = number;
    AName = name;
    ACurr = currency;
    ABal = balance;
}

void CAccount::print() {
    string currency;

    switch(this->ACurr){
        case EURO:
            currency = " EURO";
            break;
        case CZK:
            currency = " CZK";
            break;
        case USD:
            currency = " USD";
            break;
        case AUD:
            currency = " AUD";
            break;
        default:
            currency = " ---";
            break;
    }

    cout << "Number: " << ANum << ", " << "Name: " << AName << ", " << "Balance: " << ABal << currency << endl;
}

void CAccount::deposit(double amount) {
    ABal += amount;
    cout << "Deposited " << amount << " EURO to account num.: " << ANum << " ..." << endl;
    print();
    cout << endl;
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

bool CAccount::withdraw(double amount) {
    if (ABal < amount) {
        cout << "Insufficient funds, your balance is: " << ABal << " EUR" << endl << endl;
        return false;
    }
    ABal -= amount;
    cout << "Withdrawn " << amount << " EURO from account num.: " << ANum << " ..." << endl;
    print();
    cout << endl;
    return true;
}

bool CAccount::transfer(CAccount *receiver, double amount) {
    double rate = 1.0;
    if (ABal < amount) {
        std::cout << "Insufficient funds, your balance is: " << ABal << " EUR" << endl << endl;
        return false;
    }
    if (receiver->ACurr != this->ACurr) {
        rate = exchangeRate(this->ACurr, receiver->ACurr);
    }
    ABal -= amount;
    receiver->ABal += amount * rate;
    cout << "Transfered " << amount << " EURO from account num.: " << ANum << " to account num.: " << receiver->ANum
         << " ..." << endl;
    print();
    receiver->print();
    cout << endl;
    return true;
}

/*

CAccount& CAccount::transfer(CAccount& account, double value) {
	if (account.ABal > value) {
		ABal += value;
		account.ABal -= value;
		cout << "Transfered " << value << " EURO from account num.: " << ANum << " to account num.: " << account.ANum << " ..." << endl << endl;
		return *this;
	}
	else
		cout << "Insufficient funds, your balance is: " << account.ABal << " EUR" << endl << endl;
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
}

void CARegular::print() {
    cout << "Number: " << ANum << ", " << "Type: " << AType << ", " << "Name: " << AName << ", "
         << "Maintanance fee: " << AMFee << " EUR" << ", " << "Balance: " << ABal << " EUR" << endl;
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
}

void CASaving::print() {
    cout << "Number: " << ANum << ", " << "Type: " << AType << ", " << "Name: " << AName << ", " << "Interest: "
         << AInt * 100 << " %" << ", " << "Interest rate: " << AIRate * 100 << " %" << ", " << "Balance: "
         << ABal << " EUR" << endl;
}