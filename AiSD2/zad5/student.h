#pragma once
#include <iostream>
#include "person.h"

using namespace std;

class Student : public Person {
private:
    string indexNumber;
    int yearOfStudy;
    double grades[10];
public:
    Student(string name, string surname, float weight, float height, int age, Gender gender, string indexNumber, int yearOfStudy, const double grades[10]);
    double calculateAverageGrade();
    string getIndexNumber();
};