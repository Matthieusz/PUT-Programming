#include <iostream>
#include <string>
#include "car.h"
#include "catalog.h"
using namespace std;

void checkRegNum(string &regNum) {
    while (true) {
        cin >> regNum;
        if (regNum.size() == 4 && isalnum(regNum[0]) && isalnum(regNum[1]) && isalnum(regNum[2]) && isalnum(regNum[3])) {
            break;
        }
    }
}

bool checkPower(string &regNumHelper) {
    for (int i = 0; i < regNumHelper.length(); i++) {
        if (regNumHelper[i] < '0' || regNumHelper[i] > '9') {
            return false;
        }
    }
    return true;
}


int main() {
    string regNum;
    string regNumHelper;
    int power;
    string weight_str;
    double weight;
    string engine_type_str;
    type engine_type;

    Catalog catalog;
    for (int i = 0; i < 6; i++) {
        checkRegNum(regNum);
        do {
            cin >> regNumHelper;
        } while(checkPower(regNumHelper) == false);
        
        power = stoi(regNumHelper);
        cin >> weight;
        cin >> engine_type_str;
        
        switch (engine_type_str[0]) {
            case 'B':
                engine_type = B;
                break;
            case 'D':
                engine_type = D;
                break;
            case 'E':
                engine_type = E;
                break;
            case 'H':
                engine_type = H;
                break;
        }
        Car car(regNum, power, weight, engine_type);
        catalog.addCar(car);
    }

    catalog.displayCars();

    return 0;
}