#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;

class Student
{
private:

    string Name;
    int Age;
public:
    Student(string, int);

    void setAge(int);
    int getAge();

    void setName(string name);
    string getName();

    void printStudentInfo();
};

#endif // STUDENT_H
