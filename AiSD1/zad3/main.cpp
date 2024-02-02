#include <iostream>
using namespace std;

int main()
{
    int zadanie;
    cin >> zadanie;
    switch (zadanie)
    {
    case 1:
    {
        const int rozmiar1 = 10;
        int tablica[rozmiar1];
        int licznik = 1;

        for (int i = 0; i < rozmiar1; i++)
        {
            cin >> tablica[i];
        }

        int max = tablica[0];

        for (int i = 1; i < rozmiar1; i++)
        {
            if (tablica[i] > max)
            {
                max = tablica[i];
                licznik = 1;
            }
            else if (tablica[i] == max)
            {
                licznik++;
            }
        }

        cout << max << " " << licznik;
        break;
    }
    case 2:
    {
        string tekst, wzorzec;
        int licznik = 0;
        cin >> tekst >> wzorzec;
        if (tekst.length() < wzorzec.length())
        {
            cout << "0";
            break;
        }
        for (int i = 0; i <= tekst.length() - wzorzec.length(); i++)
        {
            bool porownanie = true;

            for (int j = 0; j < wzorzec.length(); j++)
            {
                if (tekst[i + j] != wzorzec[j])
                {
                    porownanie = false;
                    break;
                }
            }

            if (porownanie == true)
            {
                licznik++;
            }
        }

        cout << licznik << endl;
        break;
    }
    case 3:
    {
        const int rozmiar2 = 10;
        double tablica[rozmiar2];

        for (int i = 0; i < 10; i++)
        {
            cin >> tablica[i];
        }

        double najmniejsza = tablica[0];
        double druga_najmniejsza = tablica[1];

        if (druga_najmniejsza == najmniejsza)
        {
            for (int i = 2; i < 10; i++)
            {
                if (tablica[i] != najmniejsza)
                {
                    druga_najmniejsza = tablica[i];
                    break;
                }
            }
            if (druga_najmniejsza == najmniejsza)
            {
                cout << "Not existing." << endl;
            }
        }

        for (int i = 2; i < 10; i++)
        {
            if (tablica[i] < najmniejsza)
            {
                druga_najmniejsza = najmniejsza;
                najmniejsza = tablica[i];
            }
            else if (tablica[i] < druga_najmniejsza && tablica[i] != najmniejsza)
            {
                druga_najmniejsza = tablica[i];
            }
        }

        if (!druga_najmniejsza == najmniejsza){
            cout << druga_najmniejsza << endl;
        }
        break;
    }
    default:
    {
        cout << "Wrong task number";
    }
    }
    return 0;
}