#include <iostream>
#include "Employee.h"
#include <vector>
#include <list>
#include <set>

using namespace std;

void print(list<Employee> &l );

int main()
{
    Employee akash("Akash", "Kupta", "manager", 7000);
    akash.print();

    Employee Muminjon("Muminjon", "Siddikov", "clearner and meat cutter", 10);
    Muminjon.print();

    std::list<Employee> list_employee;

    list_employee.push_front(akash);
    list_employee.push_back(Muminjon);

    cout << "List of the employees : \n";
    print(list_employee);

    

    return 0;
}

void print(list<Employee> &l)
{
    list<Employee>::iterator it;

    for(it = l.begin(); it != l.end(); ++it)
        cout << *it << "\n---------------------\n";
}