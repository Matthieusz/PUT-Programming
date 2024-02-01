#include <iostream>
#include "person.h"
#include "student.h"
#include "course.h"
#include "staff.h"
using namespace std;

int main() {
    string courseName;
    string name;
    string surname;
    float weight;
    float height;
    int age;
    string genderInput;
    Gender gender;
    string index;
    int year;
    float grade;
    double grades[5];
    string companyName;
    string job;
    float salary;
    float seniority;
    
    cin >> courseName;
    Course course(courseName);
    
    for (int i = 0; i < 10; i++) {
        cin >> name >> surname >> weight >> height >> age >> genderInput >> index >> year;
        if (genderInput == "K") {
            gender = K;
        } else {
            gender = M;
        }
        for (int j = 0; j < 5; j++) {
            cin >> grade;
            grades[j] = grade;
        }
        Student student(name, surname, weight, height, age, gender, index, year, grades[5]);
        course.addStudent(student, year);
    }

    cin >> year;
    course.bestStudents(year);

    cin >> name >> surname >> weight >> height >> age >> genderInput >> companyName >> job >> salary >> seniority;
    if (genderInput == "K") {
        gender = K;
    }
    else {
        gender = M;
    }
    Staff staff1(name, surname, weight, height, age, gender, companyName, job, salary, seniority);

    cin >> name >> surname >> weight >> height >> age >> genderInput >> companyName >> job >> salary >> seniority;
    if (genderInput == "K") {
        gender = K;
    }
    else {
        gender = M;
    }
    Staff staff2(name, surname, weight, height, age, gender, companyName, job, salary, seniority);
    
    cout << staff1.timeLeftToRetire() << " " << staff2.timeLeftToRetire();
    
    return 0;
}