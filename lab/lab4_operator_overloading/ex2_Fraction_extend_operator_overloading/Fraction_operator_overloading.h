#pragma once

#ifndef FRACTION_OPERATOR_OVERLOADING_H_KNOWN
#define FRACTION_OPERATOR_OVERLOADING_H_KNOWN
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
		bool operator<(Fraction &o);
        bool operator<=(Fraction &o);
        bool operator>(Fraction &o);
        bool operator>=(Fraction &o);
        bool operator==(Fraction &o);
        bool operator!=(Fraction &o);
		Fraction& operator+(const Fraction &o);
        Fraction& operator-(const Fraction &o);
        Fraction& operator*(const Fraction &o);
        Fraction& operator/(const Fraction &o);

        friend ostream& operator<< (ostream &stream, const Fraction &o);
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

Fraction& Fraction::operator*(const Fraction &o)
{
    Fraction *result = new Fraction;
    result->num = num * o.num;
    result->denom = denom * o.denom;

    int gcd = GCD(result->num, result->denom);

    if(gcd != 1)
    {
        result->num /= gcd;
        result->denom /= gcd;
    }
    return *result;
}

Fraction& Fraction::operator/(const Fraction &o)
{
    Fraction *result = new Fraction;
    result->num = num * o.denom;
    result->denom = denom * o.num;

    int gcd = GCD(result->num, result->denom);

    if(gcd != 1)
    {
        result->num /= gcd;
        result->denom /= gcd;
    }
    return *result;
}

int LCM(int a, int b)
{
	return (a * b) / GCD(a, b);
}

Fraction& Fraction::operator+(const Fraction &o)
{
    Fraction *result = new Fraction;
	result->denom = LCM(denom, o.denom);
	int top1 = result->denom/denom;
	int top2 = result->denom/o.denom;

	result->num = (top1*num) + (top2 * o.num);
	int gcd = GCD(result->num, result->denom);
	if( gcd != 1)
	{
		result->num /= gcd;
		result->denom /= gcd; 
	}

	return *result;
}

Fraction& Fraction::operator-(const Fraction &o)
{
    Fraction *result = new Fraction;
	result->denom = LCM(denom, o.denom);
	int top1 = result->denom/denom;
	int top2 = result->denom/o.denom;
    result->num = (top1*num) - (top2 * o.num);
    int gcd = GCD(result->num, result->denom);
	if( gcd != 1)
	{
		result->num /= gcd;
		result->denom /= gcd; 
	}

	return *result;
}

ostream& operator<< (ostream &stream, const Fraction &o)
{
    stream << o.num << " / " << o.denom;
    return stream;
}

bool Fraction::operator<(Fraction &o)
{
	int top1 = num * o.denom;
	int top2 = denom * o.num;

	if(top1 < top2)
		return true;
	return false;
}

bool Fraction::operator<=(Fraction &o)
{
    int top1 = num * o.denom;
	int top2 = denom * o.num;

	if(top1 <= top2)
		return true;
	return false;
}

bool Fraction::operator>(Fraction &o)
{
    int top1 = num * o.denom;
	int top2 = denom * o.num;

	if(top1 > top2)
		return true;
	return false;
}

bool Fraction::operator>=(Fraction &o)
{
    int top1 = num * o.denom;
	int top2 = denom * o.num;

	if(top1 >= top2)
		return true;
	return false;
}

bool Fraction::operator==(Fraction &o)
{
    int top1 = num * o.denom;
	int top2 = denom * o.num;

	if(top1 == top2)
		return true;
	return false;
}

bool Fraction::operator!=(Fraction &o)
{
    int top1 = num * o.denom;
	int top2 = denom * o.num;

	if(top1 != top2)
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