#include <iostream>
#include "Array.h"

using namespace std;

void Merge_Sort(int* arr, int const begin, int const end);
void Merge(int* arr, int const left, int const mid, int const right);

int main()
{
    Array<int> a(7);

    a.read();
    a.print();
    cout << "\n\nMin: " << a.min();
    cout << "\n\nMax: " << a.max();
    a.reverse();
    cout << "\n\nArray is reversed: ";
    a.print();
    cout << "\n\nArray has been sorted : \n";
    a.print();

     puts("\n\n");
    return 0;
}




