#include <iostream>
#include "wektor.h"
using namespace std;

Wektor::Wektor(int rozmiar){
    iloscElementow_ = rozmiar;
    if(rozmiar > 1 && rozmiar < MAX_ROZMIAR_){
        for(int i = 0; i < rozmiar; i++){
            tab[i] = 0;
        }
    }
}

//Metody

int Wektor::podaj(int index){
    if(index >= 0 && index <= iloscElementow_){
        return tab[index];
    } 
    else 
    {
        return tab[0];
    }
}

void Wektor::wpisz(int index, double wartosc){
    if(index >= 0 && index <= iloscElementow_){
        tab[index] = wartosc;
    }
}

int Wektor::rozmiar(){
    return iloscElementow_;
}

void Wektor::dodaj(Wektor &wektor){
    for (int i = 0; i < iloscElementow_; i++){
        tab[i] += wektor.tab[i];
    }
}

//Przeciazenia

double& Wektor::operator[] (int i){
    if(i >= 0 && i < iloscElementow_){
        return tab[i];
    }
    else 
    {
        return tab[0];
    }
}

Wektor& Wektor::operator+= (const Wektor wektor){
    for (int i = 0; i < iloscElementow_; i++){
       tab[i] += wektor.tab[i];
    }
    return *this;
}

Wektor& Wektor::operator-= (const Wektor wektor){
    for (int i = 0; i < iloscElementow_; i++){
        tab[i] -= wektor.tab[i];
    }
    return *this;
}

Wektor& Wektor::operator= (const Wektor &wektor){
    iloscElementow_ = wektor.iloscElementow_;
    for (int i = 0; i < iloscElementow_; i++){
        tab[i] += wektor.tab[i];
    }
    return *this;
}

