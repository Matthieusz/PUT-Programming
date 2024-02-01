#include <iostream>
#include "building.h"
#include <string>
using namespace std;

Building::Building() {

}

Building::Building(string buildingName, float x, float y, float height) :
    buildingName_(buildingName), gps_x(x), gps_y(y), height_(height) {}

void Building::setName() {
    string name;
    cin >> name;
    buildingName_ = name;
}

void Building::setX() {
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
    gps_x = stof(input);
}

void Building::setY() {
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
    gps_y = stof(input);
}

float Building::getXYSum() {
    return gps_x + gps_y;
}

void Building::setHeight() {
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
    height_ = stof(input);
}

void Building::displayBuildingInfo() {
    cout << buildingName_ << " " << gps_x << " " << gps_y << " " << height_ << " ";
}
