#pragma once
#include <iostream>
using namespace std;

class Circle {
private:
    string name;
    float radius;

public:
    float calculateCircumference() const {
        return 2 * 3.14 * radius;
    }

    void displayAttributes() const {
        cout << name << " " << calculateCircumference() << " ";
    }

    void inputData() {
        cin >> name >> radius;
    }
};