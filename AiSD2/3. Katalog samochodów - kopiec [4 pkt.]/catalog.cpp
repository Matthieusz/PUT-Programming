#include "catalog.h"
#include <iostream>
using namespace std;

Catalog::Catalog() : index(0) {}

int Catalog::root(int parent) {
    int left = 2 * parent;
    int right = left + 1;
    if (left > index)  {
        return 0;
    }
    if (right > index || tab[left].getPower() < tab[right].getPower()){ 
        return left;
    }
    return right;
}

void Catalog::addCar(Car &car) {
    int child = ++index;
    int parent = child / 2;
    while (parent && tab[parent].getPower() > car.getPower()) {
        tab[child] = tab[parent];
        child = parent;
        parent = parent / 2;
    }
    tab[child] = car;
}


void Catalog::removeCar() {
    Car lastItem = tab[index--];
    int x = 1;
    int y = root(1);
    while (y && tab[y].getPower() < lastItem.getPower()) {
        tab[x] = tab[y];
        x = y;
        y = root(y);
    }
    tab[x] = lastItem;
}

void Catalog::displayCars() {
    for (int i = 1; i < 6; i++) {
       cout << tab[1].getRegNum() << " " << tab[1].getPower() << " ";
        removeCar();
    }
        cout << tab[1].getRegNum() << " " << tab[1].getPower();
}