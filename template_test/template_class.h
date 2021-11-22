
#pragma once
#ifndef Name_H
#define Name_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;


class Name
{

    private:

    string mem1;
    string mem2;
    int mem3;
    float mem4;
    double mem5;

    public:

    Name(): mem1{""}, mem2{""}, mem3{0}, mem4{0.0f}, mem5{0.0}
    {   }

    Name(string n, string m, int i, float f, double d): mem1{n}, mem2{m}, mem3{i}, mem4{f}, mem5{d}
    {   cout << "\n object has been created " << endl; }

    ~Name(); 

    Name(const Name &o);

    void setmem1(string m) {mem1 = m; }
    void setmem2(string m) {mem2 = m; }
    void setint(int i) {mem3 = i; }
    void setfloat(float f) {mem4 = f; }
    void setdouble(double d) {mem5 = d; }

    string getmem1() {return mem1; }
    string getmem2() {return mem2; }
    int getint() {return mem3; }
    float getfloat() {return mem4; }
    double getdouble() {return mem5; }

    friend ostream& operator<< (ostream& stream, const Name &o);

    Name& operator= (const Name &o);


};

Name::~Name()
{
    cout << "\n object has been destroyed " << endl;
}

Name::Name(const Name &o)
{

}

ostream& operator<< (ostream& stream, const Name &o)
{
    stream << " " << o.mem1 << endl;

    return stream;
}


Name& Name::operator= (const Name &o)
{
    if(this != &o)
    return *this;
}

#endif