

#include <iostream>
#include "Bank_Account.h"

using namespace std;

int main()
{
    cout << endl;
    Bank_Account mePolski("5169 3100 1306 7995", "Bank Polski", "Fozilbek Khiolboev");

    mePolski.addoperation(-50);
    mePolski.addoperation(-120);
    mePolski.addoperation(-200);
    mePolski.addoperation(-20);
    mePolski.addoperation(-400);
    mePolski.addoperation(-170);
    mePolski.addoperation(-70);
    mePolski.addoperation(-215);
    mePolski.addoperation(-280);
    mePolski.addoperation(-140);
    mePolski.addoperation(-520);

    mePolski.addoperation(400);
    mePolski.addoperation(780);
    mePolski.addoperation(900);
    mePolski.addoperation(1000);
    mePolski.addoperation(300);

    cout << mePolski << endl;

    cout << "\nGet incomes:  " << mePolski.getincomes() << endl;
    cout << "get outcomes: " << mePolski.getoutcomes() << endl;
    cout << mePolski[14] << endl;

    puts("\n\n");
    return 0;
}