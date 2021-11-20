

#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

class Employee
{
    private:
    string name;
    string surname;
    string position;
    float salary;
    
    public:
    Employee(string n="", string s="", string p="", float m=0): name{n}, surname{s}, position{p}, salary{m}
    {  cout << name << " object is created " << endl; }
    ~Employee();

    void setname(string n) {name = n; }
    void setsurname(string s) {surname = s; }
    void setposition(string pos) {position = pos; }
    void setsalarty(float s) {salary = s; }

    string getname() {return name; }
    string getsurname() {return surname; }
    string getposition() {return position; }
    float getsalary() {return salary; }

    void incSalary(float s);

    void print();
    friend ostream& operator<< (ostream& stream, const Employee &o);
};

void Employee::incSalary(float s)
{
    if(s <= 0)
        throw runtime_error("Negative can not be!");
    salary = s;
}

Employee::~Employee()
{
    cout << name << " object is destroyed " << endl;
}

void Employee::print()
{
    cout << endl;
    cout << "Name: " << name << endl;
    cout << "Surname: " << surname << endl;
    cout << "Position: " << position << endl;
    cout << "Salary: " << salary  << " zl"<< endl;
}

ostream& operator<< (ostream& stream, const Employee &o)
{
    stream << "Name: " << o.name << endl;
    stream << "Surname: " << o.surname << endl;
    stream << "Position: " << o.position << endl;
    stream << "Salary: " << o.salary  << " zl"<< endl;
    return stream;

}