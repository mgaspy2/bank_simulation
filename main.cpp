#include "Account.h"
#include "Bank.h"

using namespace std;

int main() {
//  CAccount methods test
    cout << "== CAccount methods test ================================================================================="
         << endl << endl;
    CAccount a00("00", "TEST0", EURO);
    CAccount a01("01", "TEST1", CZK, 3000);
    CARegular a02("02", "TESTr2", EURO, 5);
    CASaving a03("03", "TESTs3", AUD, 0.025, 10000);

    a00.print();
    a01.print();
    a02.print();
    a03.print();
    cout << endl;

    a00.deposit(100);
    a01.withdraw(500);
    a02.deposit(5000);
    a03.withdraw(5000);
    a00.transfer(a01, 50);
    a01.transfer(a00, 1250);
    a02.transfer(a03, 1000);
    a03.transfer(a02, 1000);

    a00.print();
    a01.print();
    a02.print();
    a03.print();
    cout << endl;

//  CBank methods test
    cout << "== CBank methods test ===================================================================================="
         << endl << endl;
    CBank b0;

    b0.addAcc(new CAccount("01", "TEST1", EURO));
    b0.addAcc(new CAccount("02", "TEST2", CZK, 10000));
    b0.addAcc(new CARegular("03", "TREG3", USD, 5));
    b0.addAcc(new CASaving("04", "TSAV4", AUD, 0.025, 6000));

    b0.print();

    b0.deposit("01", 500);
    b0.deposit("03", 5000);
    b0.withdraw("02", 5000);
    b0.withdraw("04", 1000);

    b0.print();

    b0.transfer("01", "02", 25);
    b0.transfer("02", "01", 625);
    b0.transfer("03", "04", 1000);
    b0.transfer("04", "03", 1000);

    b0.print();

    b0.simulation(100);

    b0.simulation(78);

    b0.simulation(185);

//    b0.simulation();             // Simulation runs until interrupted

    return 0;
}
