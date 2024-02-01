#include <iostream>

using namespace std;

int sprawdzWygrana(char plansza[3][3], char gracz) {
    for (int i = 0; i < 3; i++) {
        if (plansza[i][0] == gracz && plansza[i][1] == gracz && plansza[i][2] == gracz) {
            return 1; 
        }
        if (plansza[0][i] == gracz && plansza[1][i] == gracz && plansza[2][i] == gracz) {
            return 1;
        }
    }

    if (plansza[0][0] == gracz && plansza[1][1] == gracz && plansza[2][2] == gracz) {
        return 1; 
    }
    if (plansza[0][2] == gracz && plansza[1][1] == gracz && plansza[2][0] == gracz) {
        return 1; 
    }

    return 0; 
}

int sprawdzRemis(char plansza[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (plansza[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1; 
}
int main() {
    char plansza[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; 
    char aktualnyGracz = 'O'; 
    int wiersz, kolumna;

    while (true) {
        cin >> wiersz >> kolumna;

        if (wiersz < 0 || wiersz >= 3 || kolumna < 0 || kolumna >= 3 || plansza[wiersz][kolumna] != ' ') {
            continue;
        }

        plansza[wiersz][kolumna] = aktualnyGracz;

        if (sprawdzWygrana(plansza, aktualnyGracz)) {
            if (aktualnyGracz == 'O'){
                cout << 1;
                break;
            } 
            else if (aktualnyGracz == 'X'){
                cout << -1;
                break;
            } 
        } else if (sprawdzRemis(plansza)) {
            cout << 0;
            break;
        }


        aktualnyGracz = (aktualnyGracz == 'O') ? 'X' : 'O';
        
        //if (aktualnyGracz == 'O') aktualnyGracz == 'X';
        //else aktualnyGracz == 'X';
    }
    return 0;
}
