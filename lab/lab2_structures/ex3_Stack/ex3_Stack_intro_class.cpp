
#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack<float> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);


    cout << "Stack:  ";
    s.print();

    return 0;
}