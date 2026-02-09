#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include "student.h"

using namespace std;

bool compare_name(Student& a, Student& b) {
    return a.getName() < b.getName();
}

bool compare_age(Student& a, Student& b) {
    return a.getAge() < b.getAge();
}

bool same_name(Student& a, string& name) {
    cout << "Name " << a.getName() << " input name " << name << endl;
    return a.getName() == name;
}

int main()
{
    int selection =0;
    vector<Student> studentList;

    studentList.push_back(Student("jani", 19));
    studentList.push_back(Student("oskari", 22));
    studentList.push_back(Student("elias", 21));
    studentList.push_back(Student("ukko", 23));
    studentList.push_back(Student("miiro", 25));

    do {
        cout << endl;
        cout << "Select" << endl;
        cout << "Add students = 0" << endl;
        cout << "Print all students = 1" << endl;
        cout << "Sort and print students according to Name = 2" << endl;
        cout << "Sort and print students according to Age = 3" << endl;
        cout << "Find and print student = 4" << endl;
        cin >> selection;

        switch(selection) {
            case 0: {
                string input_name;
                int input_age;
                cout << "Student name ?" << endl;
                cin >> input_name;
                cout << "Student age ?" << endl;
                cin >> input_age;
                Student new_student(input_name, input_age);
                studentList.push_back(new_student);
                // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
                // Lisää uusi student StudentList vektoriin.
                break;
            }
            case 1:
            {
                for(int i = 0; i < studentList.size(); i++) {
                    cout << studentList.at(i).getName() << endl;
                }
                // Tulosta StudentList vektorin kaikkien opiskelijoiden
                // nimet.
                break;
            }

            case 2: {
                sort(studentList.begin(), studentList.end(), compare_name);

                for(int i = 0; i < studentList.size(); i++) {
                    studentList.at(i).printStudentInfo();
                }

                // Järjestä StudentList vektorin Student oliot nimen mukaan
                // algoritmikirjaston sort funktion avulla
                // ja tulosta printStudentInfo() funktion avulla järjestetyt
                // opiskelijat
                break;
            }

            case 3: {
                sort(studentList.begin(), studentList.end(), compare_age);

                for(int i = 0; i < studentList.size(); i++) {
                    studentList.at(i).printStudentInfo();
                }
                // Järjestä StudentList vektorin Student oliot iän mukaan
                // algoritmikirjaston sort funktion avulla
                // ja tulosta printStudentInfo() funktion avulla järjestetyt
                // opiskelijat
                break;
            }
            case 4: {
                cout << "Student to be found name = ?" << endl;
                string name_to_find;
                cin >> name_to_find;

                const auto it = find_if(studentList.begin(), studentList.end(),
                    [&](Student& student) {
                        cout << "lambda" << endl;
                        return same_name(student, name_to_find);
                    }
                );

                if(it != studentList.end()) {
                    cout << "Student found:" << endl;
                    it->printStudentInfo();
                }

                /*
                for(auto it = studentList.begin(); it != studentList.end(); ++it) {
                    if(it->getName() == name_to_find) {
                        cout << "Student found:" << endl;
                        it->printStudentInfo();
                    }
                }
                */

                // Kysy käyttäjältä opiskelijan nimi
                // Etsi studentListan opiskelijoista algoritmikirjaston
                // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
                // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
                break;
            }
            default: {
                cout<< "Wrong selection, stopping..."<<endl;
                break;
            }
        }
    } while(selection < 5);

	return 0;
}
