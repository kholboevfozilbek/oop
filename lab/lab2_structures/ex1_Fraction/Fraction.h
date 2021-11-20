#pragma once

#ifndef FRACTION_H_KNOWN
#define FRACTION_H_KNOWN
#include <iostream>
#include <stdexcept>
using namespace std;

struct Fraction
{
	private:
		int num;
		int denom=1;
	public:
		Fraction(int _n=1, int _d=1): num{_n}, denom{_d}
		{	}

		void read();
		void print();
		bool isGreater(Fraction &o);
		Fraction sum(Fraction &o);
        Fraction product(Fraction &o);
};


int GCD(int a, int b)
{
	int x = a;
	int y = b;

	while (x != y)
	{
		if(x > y)
			x = x - y;
		else
			y = y - x;
	}
	return x;
	
}

Fraction Fraction::product(Fraction &o)
{
    int nnum = num * o.num;
    int ddenom= denom * o.denom;

    int gcd = GCD(nnum, ddenom);

    if(gcd != 1)
    {
        nnum /= gcd;
        ddenom /= gcd;
    }
    return Fraction(nnum, ddenom);
}


int LCM(int a, int b)
{
	return (a * b) / GCD(a, b);
}

Fraction Fraction::sum(Fraction &o)
{
	int common_denom = LCM(denom, o.denom);
	int top1 = common_denom/denom;
	int top2 = common_denom/o.denom;

	int nnum = (top1*num) + (top2 * o.num);
	int gcd = GCD(nnum, common_denom);
	if( gcd != 1)
	{
		nnum /= gcd;
		common_denom /= gcd; 
	}

	return Fraction(nnum, common_denom);
}

bool Fraction::isGreater(Fraction &o)
{
	int top1 = num * o.denom;
	int top2 = denom * o.num;

	if(top1 > top2)
		return true;
	return false;
}

void Fraction::print()
{
	cout << num << " / " << denom << endl;
}

void Fraction::read()
{
	cout << "\nEnter the numerator: "; cin >> num;
	cout << "Enter trhe denominator: "; cin >> denom;
}


#endif