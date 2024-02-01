#include <iostream>
#include "person.h"
using namespace std;

Person::Person(string name, string surname, float weight, float height, int age, Gender gender)
    : name_(name), surname_(surname), weight_(weight), height_(height), age_(age)
{
    if (gender == M) {
        gender_ = M;
    }
    else gender_ = K;
}

void Person::displayInfo() {
    cout << name_ << " " << surname_ << " " << weight_ << " " << height_ << " " << age_ << " ";
}

float Person::countBMI() {
    return weight_ / (height_ * height_);
}

int Person::getAge() {
    return age_;
}