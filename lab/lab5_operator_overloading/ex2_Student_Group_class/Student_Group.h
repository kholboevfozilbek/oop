
#include <iostream>
#include <stdexcept>
#include <string>
#include <list>
#include <set>

using namespace std;

class Student
{
    private:
    string name;
    string surname;
    int index_number;
    list<float> marks;

    public:

    Student(): name{""}, surname{""}, index_number{0}
    {   cout << "\nStudent has been created " << endl; }
    Student(string n, string s, int i): name{n}, surname{s}, index_number{i}
    {   }
    ~Student();
    Student(const Student &o);

    void setname(string n) {name = n; }
    void setsurname(string s) {surname = s; }
    void setindex(int n);
    void setall(string n, string s, int index);
    string getname() {return name; }
    string getsurname() {return surname; }
    int getindexnumber() {return index_number; }

    void addMark(float n_m);
    friend ostream& operator<< (ostream& stream, const Student &o);
    Student& operator= (const Student &o);
    float avgGrade();
    void display_marks();
};

/*class Group
{
    private:
    unsigned int group_number;
    std::set<Student> student_list;

    public:
    Group(unsigned int g_n=0): group_number{g_n}
    { cout << "\nGroup of students is created" << endl; }
    ~Group();

    void setgroup_num(unsigned int g_n) {if(g_n <= 0) throw runtime_error("bad group number!"); group_number = g_n; }
    unsigned int getgroup_num() {return group_number; }
    void addStudent(Student &o);
    ///void removeStudent(Student &o);
};

Group::~Group()
{
    cout << "\nGroup of the students has been deleted" << endl;
}

void Group::addStudent(Student &o)
{
    student_list.insert(o);
}*/

class Group
{
    private:
    int group_number;
    std::set<Student*> student_list;

    public:
    Group(int g_n=0): group_number{g_n}
    {   }

    void setgroup_num(int g_n) {group_number = g_n; }
    int getgroup_num() {return group_number; }

    void addStudent(Student *o);
    void removeStudent(int index);
    friend ostream& operator<< (ostream& stream, const Group &o);
};

void Group::addStudent(Student *o)
{
    student_list.insert(o);
}

void Group::removeStudent(int index)
{
    for(auto it = student_list.begin(); it != student_list.end(); ++it)
    {
        if((*it)->getindexnumber() == index)
        {
            student_list.erase(*it);
            cout << "\nStudent is removed from list " << endl;
        }
    }

    cout << "\nThere is no such student with tghis index number! " << endl;
}

ostream& operator<< (ostream& stream, const Group &o)
{
    stream << "\nGroup number:  " << o.group_number << endl;
    stream << "Number of students:  " << o.student_list.size() << endl;

    for(auto it = o.student_list.begin(); it != o.student_list.end(); ++it)
    {
        stream << "\nName: " << (*it)->getname() << endl;
        stream << "Surname: " << (*it)->getsurname() << endl;
        stream << "Index: " << (*it)->getindexnumber() << endl;
        stream << "Marks: "; (*it)->display_marks();
        cout << "\n-------------------------------\n";
    }
}


Student::~Student()
{
    cout << "\nStudent has been deleted " << endl;
}

void Student::setindex(int n)
{
    if(n <= 0)
        throw runtime_error("bad index number!");
    index_number = n; 
}

void Student::addMark(float n_m)
{
    if(n_m < 2 || n_m > 5)
        throw runtime_error("bad mark is given!");
    marks.push_back(n_m);
}

void Student::setall(string n, string s, int index)
{
    if(index <= 0 )
        throw runtime_error("bas index is given!");
    name = n;
    surname = s;
    index_number = index;
}

ostream& operator<< (ostream& stream, const Student &o) 
{
    stream << "Name: " << o.name << endl;
    stream << "Surname: " << o.surname << endl;
    stream << "Index: " << o.index_number << endl;
    stream << "Marks: ";

    for (auto it = o.marks.begin(); it != o.marks.end(); ++it)
    {
        cout << *it << "  ";
    }
    cout << endl;
    return stream;
}

void Student::display_marks()
{
    for (auto it = marks.begin(); it != marks.end(); ++it)
    {
        cout << *it << "  ";
    }
}

float Student::avgGrade()
{
    float sum = 0.0f;
    for (auto it = marks.begin(); it != marks.end(); ++it)
    {
        sum += *it;
    }
    return (float)sum/marks.size();
}

Student::Student(const Student &o)
{
    name = o.name;
    surname = o.surname;
    index_number = o.index_number;
    
    for(auto it2 = o.marks.begin(); it2 != o.marks.end(); ++it2)
    {
        marks.push_back(*it2);
    }
    cout << "\nStudent object is copied " << endl;
}

Student& Student::operator= (const Student &o)
{
    name = o.name;
    surname = o.surname;
    index_number = o.index_number;

    marks.clear();

    for(auto it2 = o.marks.begin(); it2 != o.marks.end(); ++it2)
    {
        marks.push_back(*it2);
    }
    return *this;
}

