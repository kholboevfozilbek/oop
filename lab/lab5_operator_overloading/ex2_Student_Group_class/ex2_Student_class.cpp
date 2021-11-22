

#include <iostream>
#include <stdexcept>
#include "Student_Group.h"

using namespace std;


int main()
{
    Student Fozil("Fozilbek", "Kholboev", 397976);
    Fozil.addMark(5);
    Fozil.addMark(4);
    Fozil.addMark(3.5);
    Fozil.addMark(3.5);
    Fozil.addMark(3);
    Student Muhammadqodir("Muhammadqodir", "Abdusalomov", 356987);
    Student Aysel("Aysel", "Maharramli", 345679);
    Student Farhad("Farhad", "Isgandarov", 365679);
    Student Akzholov("Batyrkhan", "Akzholov", 375679);
    Student Mansurjon("Mansurjon", "Zokirjonov", 398564);
    

    cout << Fozil << endl;
    cout << "\n\nAvg grade: " << Fozil.avgGrade() << endl;

    Group g(2);

    cout << "\n\nGroup number: " << g.getgroup_num() << endl;
    g.addStudent(&Fozil);
    g.addStudent(&Muhammadqodir);
    g.addStudent(&Aysel);
    g.addStudent(&Farhad);
    g.addStudent(&Akzholov);
    g.addStudent(&Mansurjon);

    cout << g << endl;

    g.removeStudent(398564);

    return 0;
}