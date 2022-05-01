#include "Account.h"
#include "Bank.h"

using namespace std;

int main() {
    CBank b0;
    auto* a00 = new CAccount("00", "TEST0", EURO, 100.25);
    auto* a01 = new CAccount("01", "TEST1", CZK, 300.75);
    auto* a02 = new CAccount("02", "TEST2", EURO);
    auto* a03 = new CARegular("03", "TREG3", EURO, 5);
    auto* a04 = new CASaving("04", "TSAV4", EURO, 0.025, 0.0025, 10000);


    b0.addAccP(a00);
    b0.addAccP(a01);
    b0.addAccP(a02);
    b0.addAccP(a03);
    b0.addAccP(a04);

    b0.printP();
    b0.printP("00");

    a00->deposit(49.5);
    b0.depositP("00", 0.25);

    a01->withdraw(100.55);
    b0.withdrawP("01", 0.25);

    a00->transfer(a01, 50);
    b0.transferP("04", "03", 50);


    b0.printP();
    return 0;
}