#pragma once
#include <iostream>
#include "shape.h"

using namespace std;

class Rectangle : public Shape {
private:
    string name;
    float length;
    float width;

public:
    float calculateCircumference() const override {
        return 2 * (length + width);
    }

    float calculateArea() const override {
        return length * width;
    }

    void displayAttributes() const override {
        cout << name << " " << length << " " << width << " " << calculateArea() << " " << calculateCircumference() << " ";
    }

    void inputData() override {
        cin >> name >> length >> width;
    }
};