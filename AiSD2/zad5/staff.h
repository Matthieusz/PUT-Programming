#pragma once
#include <iostream>
#include "person.h"

class Staff : public Person {
private:
    string companyName;
    string position;
    float salary;
    float yearsOfExperience;
public:
    Staff(string name, string surname, float weight, float height, int age, Gender gender, string companyName, string position, float salary, float yearsOfExperience);
    int calculateYearsToRetirement();
};