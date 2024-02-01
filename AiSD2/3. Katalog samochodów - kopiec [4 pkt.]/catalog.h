#pragma once
#include "car.h"

class Catalog {
public:
    Catalog();

    void addCar(Car &car);
    int root(int parent);
    void removeCar();
    void displayCars();
private:
    Car tab[7];
    int index;
};