#pragma once
#include <iostream>
using namespace std;

enum Gender {
    M,
    K
};

class Person {
private:
    string name_;
    string surname_;
    float weight_;
    float height_;
    int age_;
protected:
    Gender gender_;
public:
    Person(string name, string surname, float weight, float height, int age, Gender gender);
    void displayInfo();
    float countBMI();
    int getAge();
};