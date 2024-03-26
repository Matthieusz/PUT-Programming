#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "vector.h"
using namespace std;

void zad1() {
    typedef int T;
    srand(time(nullptr));
    int n;
    cout << "Podaj rozmiar wektora V1: ";
    try {
        cin >> n;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Invalid input. Please enter a number.");
        }
        Vector<int> v1(n);
        for (size_t i = 0; i < n; i++){
            v1[i] = rand() % 100;
        }
        cout << "V1: " << v1 << endl << endl;
        cout << "Ktory element V1 chcesz wyswietlic? (od 0 do " << (n - 1) << "): ";
        cin >> n;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Invalid input. Please enter a number.");
        }
        cout << n << "-ty element V1 to: " << v1[n] << endl << endl;
        cout << "Podaj rozmiar wektora V2: ";
        cin >> n;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Invalid input. Please enter a number.");
        }
        Vector<int> v2(n);
        for (size_t i = 0; i < n; i++) {
            v2[i] = rand() % 100;
        }
        cout << "V2: " << v2 << endl << endl;
        cout << "V1 + V2: " << (v1 + v2) << endl;
        cout << "V1 - V2: " << (v1 - v2) << endl;
    } catch (const std::out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    } catch (const std::domain_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    cin.ignore(2);
}

int main() {
    do {
        int task;
        cout << "Wybierz zadanie [1,7]: ";
        cin >> task;
        switch (task)
        {
        case 1:
            cout << "Zadanie 1(1/2/3)" << endl;
            zad1();
            break;
        case 7:
            cout << "Zadanie 7" << endl;
            //zad7();
            break;
        default:
            cout << "Nie ma takiego zadania" << endl;
            break;
        }
    } while (true);
    return 0;
}