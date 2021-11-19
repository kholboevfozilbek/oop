#include <iostream>

using namespace std;

bool isTriangle(int a, int b, int c);


int main()
{
	if(isTriangle(5, 8, 6) == true)
		cout << "Yes this sides can be triangle " << endl;
	else
		cout << "NOOO this can not be a triangle! " << endl;
	return 0;
}

bool isTriangle(int a, int b, int c)
{
	if(a+b <= c || a+c <= b || b+c <= a)
		return false;
	return true;
}
