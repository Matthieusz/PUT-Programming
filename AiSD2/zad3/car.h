#pragma once
#include <string>
using namespace std;

enum type {B, D, E, H};

class Car {
public:
    Car();
    
    Car(string regNum, int power, double weight, type engine);
    string getRegNum(){ 
        return reg_num; 
    }
    int getPower(){ 
        return power; 
    } 
    double getWeight(){ 
        return weight; 
    }
    type getEngineType(){ 
        return engine_type; 
    } 
private:
    string reg_num;
    int power;
    double weight;
    type engine_type;
};