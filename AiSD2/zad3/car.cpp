#include "car.h"
#include <iostream>
using namespace std;

Car::Car() {}

Car::Car(string regNum, int power, double weight, type engine): 
reg_num(regNum), power(power), weight(weight), engine_type(engine) {}