
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


    cout << "\n\nStack:  ";
    s.print();
    cout << "Size: " << s.size() << endl;

    cout << "\nPop: " << s.pop() << endl;
    cout << "\nPop: " << s.pop() << endl;

    cout << "\nStack:  ";
    s.print();
    cout << "Size: " << s.size() << endl;
    
    s.clear();
    
    cout << "\nStack:  ";
    s.print();
    cout << "Size: " << s.size() << endl;

    puts("\n\n");
    return 0;
}