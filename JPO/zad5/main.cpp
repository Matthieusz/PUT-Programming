#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void zad1() {
    int n;
    cout << "Podaj ilosc elementow(n): " << endl;
    cin >> n; 
    vector<int> vec(n);
    srand(time(0));

    for (int i = 0; i < n; i++) {
        vec[i] = rand() % 41 - 20;
    }

    cout << "Wektor(indeksacja): ";
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    cout << "Wektor(iterator): ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Z uzyciem find :" << endl;
    for (int i = 20; i >= -20; i--)
    {
        if( find(vec.begin(), vec.end(), i) == vec.end() )
        {
            if ( *vec.end() != i ) continue;
            else 
            {
                cout << "Pozostaly najwiekszy element: " << *vec.end() << endl;
                break;
            }
        }
        else 
        {
            cout << "Pozostaly najwiekszy element: " << *find(vec.begin(), vec.end(), i) << endl;
            break;
        }
    }
    for (int i = -20; i <= 20; i++)
    {
        if( find(vec.begin(), vec.end(), i) == vec.end() )
        {
            if ( *vec.end() != i ) continue;
            else 
            {
                cout << "Pozostaly najmniejszy element: " << *vec.end() << endl;
                break;
            }
        }
        else 
        {
            cout << "Pozostaly najmniejszy element: " << *find(vec.begin(), vec.end(), i) << endl;
            break;
        }
    }
    vector<int>::iterator min_value = min_element(vec.begin(), vec.end());
    vector<int>::iterator max_value = max_element(vec.begin(), vec.end());
    cout << "Najmniejszy element: " << *min_value << endl;
    cout << "Najwiekszy element: " << *max_value << endl;

    for (int i = -20; i <= 20; i++) {
        int count = std::count(vec.begin(), vec.end(), i);
        if (count > 0) {
            cout << "Liczba " << i << " wystapila " << count << " razy." << endl;
        }
    }

    // a. 
    sort(vec.begin(), vec.end());
    
    cout << "Wektor po sortowaniu rosnacym: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // b.
    sort(vec.begin(), vec.end(), greater<int>());
    
    cout << "Wektor po sortowaniu malejacym: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // c.
    sort(vec.begin(), vec.end(), [](int a, int b) {
        return abs(a) > abs(b);
    });
    
    cout << "Wektor po sortowaniu wg. wartosci bezwzglednej: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Wektor po usunieciu: ";
    vector<int>::iterator max_it = max_element(vec.begin(), vec.end());
    vec.erase(max_it);
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}
void zad2() {
    int n;
    cout << "Podaj ilosc elementow(n): " << endl;
    cin >> n;
    list<int> lista;
    srand(time(0));

    for (int i = 0; i < n; i++) {
        lista.push_back(rand() % 41 - 20);
    }

    cout << "Lista: ";
    for (list<int>::iterator it = lista.begin(); it != lista.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;


    cout << "Z uzyciem find :" << endl;
    for (int i = 20; i >= -20; i--)
    {
        if( find(lista.begin(), lista.end(), i) == lista.end() )
        {
            if ( *lista.end() != i ) continue;
            else 
            {
                cout << "Pozostaly najwiekszy element: " << *lista.end() << endl;
                break;
            }
        }
        else 
        {
            cout << "Pozostaly najwiekszy element: " << *find(lista.begin(), lista.end(), i) << endl;
            break;
        }
    }
    for (int i = -20; i <= 20; i++)
    {
        if( find(lista.begin(), lista.end(), i) == lista.end() )
        {
            if ( *lista.end() != i ) continue;
            else 
            {
                cout << "Pozostaly najmniejszy element: " << *lista.end() << endl;
                break;
            }
        }
        else 
        {
            cout << "Pozostaly najmniejszy element: " << *find(lista.begin(), lista.end(), i) << endl;
            break;
        }
    }

    list<int>::iterator min_value = min_element(lista.begin(), lista.end());
    list<int>::iterator max_value = max_element(lista.begin(), lista.end());
    cout << "Najmniejszy element: " << *min_value << endl;
    cout << "Najwiekszy element: " << *max_value << endl;

    for (int i = -20; i <= 20; i++) {
        int count = std::count(lista.begin(), lista.end(), i);
        if (count > 0) {
            cout << "Liczba " << i << " wystapila " << count << " razy." << endl;
        }
    }

    // a.
    lista.sort();
    cout << "Lista po sortowaniu rosnacym: ";
    for (list<int>::iterator it = lista.begin(); it != lista.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // b. 
    lista.sort(greater<int>());
    cout << "Lista po sortowaniu malejacym: ";
    for (list<int>::iterator it = lista.begin(); it != lista.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // c.
    lista.sort([](int a, int b) {
        return abs(a) > abs(b);
    });
    
    cout << "Lista po sortowaniu wg. wartosci bezwzglednej: ";
    for (list<int>::iterator it = lista.begin(); it != lista.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Lista po usunieciu: ";
    list<int>::iterator max_it = max_element(lista.begin(), lista.end());
    lista.erase(max_it);
    for (list<int>::iterator it = lista.begin(); it != lista.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    do {
        int task;
        cout << "Wybierz zadanie [1,2]: ";
        cin >> task;
        switch (task)
        {
        case 1:
            cout << "Zadanie 1(1/3/4/5/6)" << endl;
            zad1();
            break;
        case 2:
            cout << "Zadanie 1(2/3/4/5/6)" << endl;
            zad2();
            break;
        default:
            cout << "Nie ma takiego zadania" << endl;
            break;
        }
    } while (true);
    return 0;
}