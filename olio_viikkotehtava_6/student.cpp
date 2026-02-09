#include "student.h"
#include <iostream>

using namespace std;

Student::Student(string name, int age) : Name(name), Age(age)
{
    cout << "Student " << this->getName() << " luotu" << endl;
}

void Student::setAge(int age)
{
    this->Age = age;
}

int Student::getAge()
{
    return this->Age;
}

void Student::setName(string name)
{
    this->Name = name;
}

string Student::getName()
{
    return Name;
}

void Student::printStudentInfo()
{
    cout << "Student " << this->getName() << " Age " << this->getAge() << endl;

}
