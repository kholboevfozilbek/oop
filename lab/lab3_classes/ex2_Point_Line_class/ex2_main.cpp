#include <iostream>
#include "Point_Line.h"

using namespace std;


int main()
{
    Point a(2, 2);
    Point b(-2, -3);

    cout << "Distance between two points:  " << a.distance(b) << endl;
    return 0;
}