#include <iostream>
using namespace std;

void sort(char arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int min{i};
        for(int j = i; j < n; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}

void sortujTablice(int tab[][5], int wiersze) {
    for (int i = 0; i < wiersze * 5 - 1; i++) {
        for (int j = 0; j < wiersze * 5 - i - 1; j++) {
            int wiersz1 = j / 5;
            int kolumna1 = j % 5;
            int wiersz2 = (j + 1) / 5;
            int kolumna2 = (j + 1) % 5;

            if (tab[wiersz1][kolumna1] > tab[wiersz2][kolumna2]) {
                int temp = tab[wiersz1][kolumna1];
                tab[wiersz1][kolumna1] = tab[wiersz2][kolumna2];
                tab[wiersz2][kolumna2] = temp;
            }
        }
    }
}

void wyswietlTablice(int tablica[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        cout << tablica[i] << " ";
    }
}

void sortowanieKoktajlowe(int tablica[10], int rozmiar) {
    bool zamieniono = true;
    int start = 0;
    int koniec = rozmiar - 1;

    while (zamieniono) {
        zamieniono = false;

        for (int i = start; i < koniec; i++) {
            if (tablica[i] < tablica[i + 1]) {
                swap(tablica[i], tablica[i + 1]);
                zamieniono = true;
            }
        }

        if (!zamieniono) {
            break;
        }

        zamieniono = false;

        for (int i = koniec - 1; i >= start; i--) {
            if (tablica[i] < tablica[i + 1]) { 
                swap(tablica[i], tablica[i + 1]);
                zamieniono = true;
            }
        }
        wyswietlTablice(tablica, rozmiar);
        
        start++;
        koniec--;
    }
}

int main(){
    int task;
    cin >> task;
    switch(task){
        case 1:{
            const int arrSize{30};
            char arr[arrSize];
            for(int i = 0; i < arrSize; i++){
                cin >> arr[i];
            }
            sort(arr, arrSize);
            for(int l = 0; l < arrSize; l++){
                cout << arr[l] << " ";
            }
            break;
        }
        case 2:{
            const int wiersze = 4;
            const int kolumny = 5;
            int tablica[wiersze][kolumny];
        
            for (int i = 0; i < wiersze; i++) {
                for (int j = 0; j < kolumny; j++) {
                    cin >> tablica[i][j];
                }
            }
            sortujTablice(tablica, wiersze);
        
            for (int i = 0; i < wiersze; i++) {
                for (int j = 0; j < kolumny; j++) {
                    cout << tablica[i][j] << " ";
                }
            }
            break;
        }
        case 3:{ // nie dziala :(
            const int rozmiar = 10;
            int tablica[rozmiar];
            
            for (int i = 0; i < rozmiar; i++) {
                cin >> tablica[i];
            }
            sortowanieKoktajlowe(tablica, rozmiar);

            break;
        }
    }
}