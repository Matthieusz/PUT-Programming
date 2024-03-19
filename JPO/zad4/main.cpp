#include <iostream>
#include "vector.h"
using namespace std;

void zad1() {
typedef int T;
    const size_t d = 10;
    Vector<T> v1(d);
    for (size_t i = 0; i < d; i++) {
        v1[i] = (T)i;
    }
    cout << "Wektor v1: " << v1 << endl;
    Vector<T> v2 = v1 + v1;
    cout << "Wektor v2: " << v2 << endl;
    cout << "v1 == v1: " << (v1 == v1 ? "TAK" : "NIE") << endl;
    cout << "v1 != v1: " << (v1 != v1 ? "TAK" : "NIE") << endl;
    cout << "v1 == v2: " << (v1 == v2 ? "TAK" : "NIE") << endl;
    cout << "v1 != v2: " << (v1 != v2 ? "TAK" : "NIE") << endl;
    Vector<T> v3(5);
    cout << "Wektor v3: " << v3 << endl;
    cout << "v1 == v3: " << (v1 == v3 ? "TAK" : "NIE") << endl;
    v3 = v1;
    cout << "Wektor v3: " << v3 << endl;
    cout << "v1 == v3: " << (v1 == v3 ? "TAK" : "NIE") << endl; 
}

int main() {
    do {
        int task;
        cout << "Wybierz zadanie [1,3,4]: ";
        cin >> task;
        switch (task)
        {
        case 1:
            cout << "Zadanie 1/2" << endl;
            zad1();
            break;
        case 4:
            cout << "Zadanie 3" << endl;
            //zad3();
            break;
        case 6:
            cout << "Zadanie 4" << endl;
            //zad4();
            break;
        default:
            cout << "Nie ma takiego zadania" << endl;
            break;
        }
    } while (true);
    return 0;
}