#include <iostream>

using namespace std;

class Car {
private:
    char registrationNumber[5];
    int enginePower;
    double weight;
    char engineType;

public:
    Car(): registrationNumber(""), enginePower(0), weight(0.0), engineType('*') {}
    Car(const char* regNum, int power, double w, char e) {
        for (int i = 0; i < 4; i++) {
            registrationNumber[i] = regNum[i];
        }
        registrationNumber[4] = '\0';
        enginePower = power;
        weight = w;
        engineType = e;
    }

    const char* getRegistrationNumber() const {
        return registrationNumber;
    }

    int getEnginePower() const {
        return enginePower;
    }

    double getWeight() const {
        return weight;
    }

    char getEngineType() const {
        return engineType;
    }
};

class CarCatalog {
private:
    int carCount;

public:
    CarCatalog() : carCount(0) {}

    Car cars[6];
    
    void displayCars() {
        for (int i = 0; i < carCount; i++) {
            cout << cars[i].getRegistrationNumber() << " " << cars[i].getEnginePower() << " ";
        }
    }

    void addCar(const Car& car) {
        if (carCount < 6) {
            cars[carCount] = car;
            carCount++;
        }
    }

    void removeCar(int i) {
        if (i < carCount - 1) {
            cars[i] = cars[carCount - 1];
        }
        carCount--; 
        return;
    }

};


void validation(string regNum, bool &valid){
    if(regNum.size() > 4) valid = false;
    for (int j = 0; j < regNum.size(); j++) {
        if (('a' > regNum[j] || regNum[j] > 'z') && ('A' > regNum[j] || regNum[j] > 'Z') && ('0' > regNum[j] || regNum[j] > '9')) {
            valid = false;
        }
        
    }
}


int main() {
    CarCatalog catalog;

    char regNum[5];
    int power;
    double weight;
    char engineType;
    bool valid;
    
    for (int i = 0; i < 6; i++) {
        do {
            valid = true;
            cin >> regNum;
            validation(regNum, valid);
        } while (not valid);

        cin >> power;

        cin >> weight;

        while (true) {
            cin >> engineType;
            if (engineType == 'B' || engineType == 'D' || engineType == 'E' || engineType == 'H') {
                break;
            }
        }

        Car car(regNum, power, weight, engineType);
        catalog.addCar(car);
    }
    catalog.removeCar(2);
    catalog.displayCars();

    return 0;
}
