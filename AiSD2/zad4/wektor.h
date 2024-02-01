#pragma once
#include <iostream>
using namespace std;

class Wektor {
    private:
        friend ostream& operator << (ostream &cout, const Wektor &wektor); 
        static const int MAX_ROZMIAR_ = 100;
        int iloscElementow_ = 0;
        
    public:
        Wektor();
        double tab[MAX_ROZMIAR_];
        Wektor(int rozmiar);
        
        int podaj(int index);
        void wpisz(int index, double wartosc);
        int rozmiar();
        void dodaj(Wektor &wektor);

        double& operator[] (int i);
        Wektor& operator+= (const Wektor wektor);
        Wektor& operator-= (const Wektor wektor);
        Wektor& operator= (const Wektor &wektor);
};