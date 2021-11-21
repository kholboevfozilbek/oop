
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <math.h>
using namespace std;

class Point
{

    private:

    int m_X;
    int m_Y;

    public:
    Point(): m_X{0}, m_Y{0}
    {   }
    Point(int x, int y): m_X{x}, m_Y{y}
    {   }
    
    void setx(int x) {m_X = x; }
    void sety(int y) {m_Y = y; }
    int getx() {return m_X; }
    int gety() {return m_Y; }
    double distance(const Point &o);
};

double Point::distance(const Point &o)
{
    return (double) sqrt(pow(o.m_X - m_X, 2) + pow(o.m_Y - m_Y, 2));
}
