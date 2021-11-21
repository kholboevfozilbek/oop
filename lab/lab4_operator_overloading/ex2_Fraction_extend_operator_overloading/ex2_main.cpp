

#include <iostream>
#include "Fraction_operator_overloading.h"
#include <stdexcept>
using namespace std;

int main()
{
    Fraction f(2, 5), g(3, 8);
    cout << f << endl;
    cout << g << endl;

    cout << f << " + " << g << " = " << f + g << endl;
    cout << f << " - " << g << " = " << f - g << endl;
    cout << f << " * " << g << " = " << f * g << endl;
    cout << f << " / " << g << " = " << f / g << endl;

    if(f < g)
        cout << "f < g" << endl;
    else if(f > g)
        cout << "f > g" << endl;
    else
        cout << "f == g" << endl;

    puts("\n\n");
    return 0;
}