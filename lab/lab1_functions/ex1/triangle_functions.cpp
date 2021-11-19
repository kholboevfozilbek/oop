#include <iostream>
#include <stdexcept>
#include <cmath>
#include <math.h>

using namespace std;

bool isTriangle(int a, int b, int c);
int perimeter(int a, int b, int c);
float area(int a, int b, int c);

int main()
{
	int a, b, c;
	char repeat;

	do
        {
	cout << "Enter the a: "; cin >> a;
        cout << "Enter the b: "; cin >> b;
        cout << "Enter the c: "; cin >> c;
        if(isTriangle(a, b, c) == true)
                cout << "Yes this sides can be triangle " << endl;
        else
                throw runtime_error("NOOO this can not be a triangle! ");
        cout << "\nPerimeter:  " << perimeter(a, b, c);
        cout << "\nArea:  " << area(a, b, c) << endl;

        cout << "You want to repeat? [y/n]: ";
        cin >> repeat;

	
	}
	while(repeat == 'y' || repeat == 'Y');

	return 0;
}

bool isTriangle(int a, int b, int c)
{
	if(a+b <= c || a+c <= b || b+c <= a)
		return false;
	return true;
}

int perimeter(int a, int b, int c)
{
	return (a + b + c);
}

float area(int a, int b, int c)
{
	float s = (a + b + c ) / 2.0;
	return sqrt(s*(s-a) * (s-b) * (s-c));
}
