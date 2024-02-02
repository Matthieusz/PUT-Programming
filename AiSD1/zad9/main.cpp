#include <iostream>
using namespace std;

void obliczStatystyki(const int tab[], int rozmiar, double& srednia, double& wariancja) {
    int suma = 0;
    for (int i = 0; i < rozmiar; i++) {
        suma += tab[i];
    }
    srednia = static_cast<double>(suma) / rozmiar;

    double sumaKwadratowRoznic = 0;
    for (int i = 0; i < rozmiar; i++) {
        sumaKwadratowRoznic += (tab[i] - srednia) * (tab[i] - srednia);
    }
    wariancja = sumaKwadratowRoznic / rozmiar;
}


int count_ones(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int find_max_ones(int arr[], int size) {
    int max_index = 0;
    int max_count = count_ones(arr[0]);

    for (int i = 1; i < size; i++) {
        int count = count_ones(arr[i]);
        if (count > max_count || (count == max_count && arr[i] < arr[max_index])) {
            max_count = count;
            max_index = i;
        }
    }

    return arr[max_index];
}

int sequenceCheck(int a, int b){
    unsigned int mask = 0x80000000;
    int size = 0;
    unsigned int secondmask;
    int counter = 0;
    unsigned int maxmask = 0xFFFFFFFF;
    for(mask = 0x80000000; mask; mask = mask >> 1){
        if(mask & a){
            break;
        }
        else if ((mask & a)==0){
            size++;
        }
    }
    secondmask = a << size;
    maxmask = maxmask << size;
    int secondsize = 32 - size;
      for(int i = 0; i <= 32 - secondsize; i++){
        if(((maxmask & b)) == (secondmask)){
            counter++;
        }
        secondmask = secondmask >> 1;
        maxmask = maxmask >> 1;
        
    }
    return counter;
    
}

int main() {
    int task;
    cin >> task;
    switch(task) {
        case 1:{
            const int rozmiar = 4;
            int tablica[rozmiar];

            for (int i = 0; i < rozmiar; i++) {
                cin >> tablica[i];
            }

            double srednia, wariancja;
            obliczStatystyki(tablica, rozmiar, srednia, wariancja);

            cout << srednia << " " << wariancja;
            break;
        }
        case 2:{
            const int size = 10;
            int arr[size];

            for (int i = 0; i < size; i++) {
                cin >> arr[i];
            }

            int result = find_max_ones(arr, size);
            cout << result;
            break;
        }
        case 3:{
            int a, b;
            cin >> a >> b;
            cout << sequenceCheck(a,b);
        }
    }
}