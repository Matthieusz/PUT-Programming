#pragma once
#include <iostream>
using namespace std;


class Animal {
private:
    string name_;
    float weight_;
    int year_;
    string identifier_;
public:
    Animal();
    Animal(string, float, int, string);
    void setName();
    void setWeight();
    void setYear();
    void setIdentifier();
    int getYear();
    float getWeight();
    void displayAnimals();
};