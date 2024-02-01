#pragma once
#include <iostream>
using namespace std;

enum Gender {M, K};
class Person {
private:
    string name;
    string surname;
    float weight;
    float height;
    int age;
protected:
    Gender gender;
public:
    Person(string name, string surname, float weight, float height, int age, Gender gender);
    void displayPerson();
    float calculateBMI();
    int getAge();
    string getName();
    string getSurname();
};