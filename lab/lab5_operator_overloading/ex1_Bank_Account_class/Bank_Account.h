
#include <iostream>
#include <string>
#include <list>
#include <string.h>
using namespace std;

class Bank_Account
{

    private:

    string account_number;
    double balance;
    list<float> operations;

    string bank_name;
    string owner_name;

    public:

    Bank_Account(): account_number{""}, balance{0.0f}, bank_name{"unknown"}, owner_name{"unknown"}
    {   cout << "\n\n A bank account has been created " << endl;}
    Bank_Account(string a_n, string b_n, string o_n): account_number{a_n}, balance{0}, bank_name{b_n}, owner_name{o_n}
    {   }
    ~Bank_Account();

    void setaccountnumber(string a_n) {account_number = a_n; }
    void setbankname(string b_n) {bank_name = b_n;}
    void setownername(string o_n){owner_name = o_n; }
    string getbankname() {return bank_name; }
    string getownername() {return owner_name; }
    string getaccountnumber() {return account_number; }
    void addoperation(float operation_amount);
    float getincomes();
    float getoutcomes();

    float& operator[] (unsigned int index);
    friend ostream& operator<< (ostream &stream, const Bank_Account &o);

};

Bank_Account::~Bank_Account()
{
    cout << "\nbank account has been deleted " << endl;
}

void Bank_Account::addoperation(float operation_amount)
{
    if(operation_amount > 0)
    {
        // if + int means <- income
        operations.push_back(operation_amount);
        balance = balance + operation_amount;
    }
    else if(operation_amount < 0)
    {
        // if - it means -> output
        operations.push_back(operation_amount);
        balance = balance + operation_amount;
    }
    else
        throw runtime_error("You can not either recieve or send 0 money! DUMB");
}


ostream& operator<< (ostream &stream, const Bank_Account &o)
{
    stream << "Bank Name: " << o.bank_name << endl;
    stream << "account number: " << o.account_number << endl;
    stream << "owner Name: " << o.owner_name << endl;
    stream << "balance:  " << o.balance << endl;
    stream << "Incomes:  ";

    
    for(auto it = o.operations.begin(); it != o.operations.end(); ++it)
    {
        if(*it > 0)
            stream << *it << "  ";
    }

    cout << "\nOutcomes:  ";
    for(auto it = o.operations.begin(); it != o.operations.end(); ++it)
    {
        if(*it < 0)
            stream << *it << "  ";
    }

    return stream;
}

float Bank_Account::getincomes()
{
    float incomes=0.0f;
    for(auto it = operations.begin(); it != operations.end(); ++it)
    {
        if(*it > 0)
            incomes += *it;
    }
    return incomes;
}

float Bank_Account::getoutcomes()
{
    float outcomes=0.0f;
    for(auto it = operations.begin(); it != operations.end(); ++it)
    {
        if(*it < 0)
            outcomes += *it;
    }
    return outcomes;
}

float& Bank_Account::operator[] (unsigned int index)
{
    if(index < 0 || index >= operations.size())
        throw runtime_error("Bad index accessing!");
    
    int count=0;
    for(auto it = operations.begin(); it != operations.end(); ++it)
    {
        if(count == index)
            return *it;
        ++count;
    }
}