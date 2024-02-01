#include <iostream>
#include"wektor.h"
using namespace std;

Wektor operator+ (Wektor wektor1, Wektor wektor2){
    for(int i = 0; i < wektor1.rozmiar(); i++){
        wektor1.tab[i] += wektor2.tab[i];
    }
    return wektor1;
}

Wektor operator- (Wektor wektor1, Wektor wektor2){
    for(int i = 0; i < wektor1.rozmiar(); i++){
        wektor1.tab[i] -= wektor2.tab[i];
    }
    return wektor1;
}

Wektor operator! (Wektor wektor){
    for(int i = 0; i < wektor.rozmiar(); i++){
        wektor.tab[i] *= -1;
    }
    return wektor;
}

ostream& operator<< (ostream &cout, const Wektor &wektor){
    cout << "[";
    for(int i = 0; i < wektor.iloscElementow_; i++){
        if(i == wektor.iloscElementow_ - 1){
            cout << wektor.tab[i];
            break;
        }
        cout << wektor.tab[i] << " ";
    }
    cout << "]";
    return cout;
}

int main()
{
   int n1, n2;
   cout << "n1="; 
   cin >> n1;
   Wektor w1(n1);
   cout << "w1=";
   double x;
   for (int i = 0; i < n1; ++i)
   {
       cin >> x;
       w1.wpisz(i, x);
   }
   
   cout << "n2="; 
   cin >> n2;
   Wektor w2(n2);
   cout << "w2=";
   
   for (int i = 0; i < n2; ++i)
   {
       cin >> x;
       w2[i] = x;
   }
   
   Wektor w3(10); 
   Wektor w4(10);
   
   w3 = w1;
   w4 = w1+w2;
   
   cout << "w1=" << w1 << endl;
   cout << "w2=" << w2 << endl;
   cout << "w3=w1=" << w3 << endl;
   cout << "w4=w1+w2" << w4 << endl;
   cout << "!w1=" << !w1 << endl;   
   cout << "w1+w4" << w1+w4 << endl;  
   cout << "w1-w4" << w1-w4 << endl;  
   
   w3.dodaj(w4);
   cout << "w3+=w4 ->" << w3 << endl;
   cout << "w2+=w3 ->" << (w2+=w3) << endl;
   cout << "w1-=w2 ->" << (w1-=w2) << endl;
}