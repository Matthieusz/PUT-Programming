#pragma once
#include <iostream>
using namespace std;

class Building {
private:
    string buildingName_;
    float gps_x, gps_y, height_;
public:
    Building();
    Building(string, float, float, float);
    void setName();
    void setX();
    void setY();
    float getXYSum();
    void setHeight();
    void displayBuildingInfo();
};