#pragma once
#include <iostream>
#include "shape.h" 

using namespace std;

class CircleShape : public Shape {
private:
string name;
    float radius;

public:
    float calculateCircumference() const override {
        return 2 * 3.14 * radius;
    }

    float calculateArea() const override {
        return 3.14 * radius * radius;
    }

    void displayAttributes() const override {
        cout << name << " " << radius << " " << calculateArea() << " " << calculateCircumference() << " ";
    }

    void inputData() override {
        cin >> name >> radius;
    }
};
