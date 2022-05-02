#include "Account.h"
#include "Bank.h"

using namespace std;

int main() {
    CBank b0;
    auto *a00 = new CAccount("00", "TEST0", EURO);
    auto *a01 = new CAccount("01", "TEST1", CZK);
    auto *a02 = new CAccount("02", "TEST2", EURO);
    auto *a03 = new CARegular("03", "TREG3", AUD, 5, 5500);
    auto *a04 = new CASaving("04", "TSAV4", USD, 0.025, 0.0025, 10100);


    b0.addAcc(a00);
    b0.addAcc(a01);
    b0.addAcc(a02);
    b0.addAcc(a03);
    b0.addAcc(a04);

    b0.print();

    a00->deposit(300);
    b0.deposit("01", 2000);

    b0.print();

    a03->withdraw(500);
    b0.withdraw("04", 100);

    b0.print();

    a00->transfer(a01, 50);
    b0.transfer("01", "02", 500);
    b0.transfer("03", "04", 1000);
    b0.transfer("04", "03", 1000);

    b0.print();

    a03->simulation(35);
    a04->simulation(35);
    a03->print();
    a04->print();
    b0.simulation(62);

    b0.print();

    return 1;
}
