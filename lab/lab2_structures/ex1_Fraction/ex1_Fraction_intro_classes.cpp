#include <iostream>
#include "Fraction.h"
using namespace std;


int main()
{
	Fraction f(4, 8);

	f.print();

	Fraction d;

	d.print();

	d.read();
	Fraction sum = d.sum(f);
	cout << "\n\nSum of the d + f = "; sum.print();
	Fraction prod  = d.product(f);

	cout << "\n\nProduct of the d * f = ";
	prod.print();


	if(d.isGreater(f) == true)
		cout << "d is greater than f " << endl;

	return 0;
}
