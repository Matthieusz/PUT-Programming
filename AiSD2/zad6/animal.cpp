#include <iostream>
#include <string>
#include "animal.h"
using namespace std;

Animal::Animal() {

}

Animal::Animal(string name, float weight, int year, string identifier) :
    name_(name), weight_(weight), year_(year), identifier_(identifier) {}

void Animal::setName() {
    string name;
    cin >> name;
    name_ = name;
}

void Animal::setWeight() {
    string input;
    bool valid = false;
    while (!valid) {
        bool dot = false;
        cin >> input;
        for (int i = 0; i < input.length(); i++) {
            if (dot == false and input[i] == '.') {
                dot = true;
                continue;
            }

            if (!(input[i] >= '0' and input[i] <= '9'))
                break;

            if (i == input.length() - 1)
                valid = true;
        }
    }
    weight_ = stof(input);
}

void Animal::setYear() {
    string input;
    bool valid = false;
    while (!valid) {
        cin >> input;
        for (int i = 0; i < input.length(); i++) {
            if (!(input[i] >= '0' and input[i] <= '9'))
                break;

            if (i == input.length() - 1)
                valid = true;
        }
    }
    year_ = stoi(input);
}

void Animal::setIdentifier() {
    string identifier;
    cin >> identifier;
    identifier_ = identifier;
}

int Animal::getYear() {
    return year_;
}

float Animal::getWeight() {
    return weight_;
}

void Animal::displayAnimals() {
    cout << name_ << " " << weight_ << " " << year_ << " " << identifier_ << " ";
}