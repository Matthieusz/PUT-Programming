#include<iostream>
#include "animal.h"
#include "building.h"
#include "template.h"
using namespace std;

void sortAnimals(Container<Animal> animals) {
    int size = animals.getCounter();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (animals.getArray()[j].getYear() < animals.getArray()[j + 1].getYear())
                animals.swapIndexes(j, j + 1);

            if (animals.getArray()[j].getYear() == animals.getArray()[j + 1].getYear())
                if (animals.getArray()[j].getWeight() > animals.getArray()[j + 1].getWeight())
                    animals.swapIndexes(j, j + 1);
        }
    }

    for (int i = 0; i < size; ++i) {
        animals.getArray()[i].displayAnimals();
    }
}

void sortBuildings(Container<Building> buildings) {
    int size = buildings.getCounter();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (buildings.getArray()[j].getXYSum() > buildings.getArray()[j + 1].getXYSum())
                buildings.swapIndexes(j, j + 1);
        }
    }

    for (int i = 0; i < size; ++i) {
        buildings.getArray()[i].displayBuildingInfo();
    }
}

int main() {
    Container<Animal> animals;
    Container<Building> buildings;

    string name;
    float weight;
    int year;
    string identifier;
    int indexToRemove;

    for (int i = 0; i < 4; ++i) {
        Animal animal;
        animal.setName();
        animal.setWeight();
        animal.setYear();
        animal.setIdentifier();

        animals.add(animal);
    }

    for (int i = 0; i < 4; ++i) {
        Building building;
        building.setName();
        building.setX();
        building.setY();
        building.setHeight();

        buildings.add(building);
    }

    cin >> indexToRemove;
    animals.remove(indexToRemove);

    sortAnimals(animals);
    sortBuildings(buildings);

    return 0;
}