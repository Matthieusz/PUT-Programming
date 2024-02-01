#pragma once
#include <iostream>

using namespace std;

class Shape {
public:
    virtual float calculateCircumference() const = 0;
    virtual float calculateArea() const = 0;
    virtual void displayAttributes() const = 0;
    virtual void inputData() = 0;
};