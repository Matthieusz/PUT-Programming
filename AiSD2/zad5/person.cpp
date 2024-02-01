#include <iostream>
#include "person.h"
using namespace std;

Person::Person(string name, string surname, float weight, float height, int age, Gender gender)
        : name(name), surname(surname), weight(weight), height(height), age(age), gender(gender) {}

void Person::displayPerson() {
    cout << name << " " << surname << " " << weight << " " << height << " " << age << " " << (gender == M ? "M" : "K") << endl;
}
float Person::calculateBMI() {
    return weight / ((height / 100) * (height / 100));
}
int Person::getAge() {
    return age;
}

string Person::getName() {
    return name;
}

string Person::getSurname() {
    return surname;
}

