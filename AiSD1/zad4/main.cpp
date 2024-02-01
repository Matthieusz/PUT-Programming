#include <iostream>
using namespace std;

int romanToArabic(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return -1;
    }
}

int main () {
    int task;
    cin >> task;
    switch (task) {
        case 1:{
            const int size = 6;
            double tab[size];
            int i = 0;
            while(i < size){
                double number;
                cin >> number;
                if (number >= 0 && number <= 10){
                    tab[i] = number;
                    i++;
                }
            }
            cout << "Resulting array: ";
            for (int j = 0; j < size; j++) {
                cout << tab[j] << " ";
            }
            break;    
            }
        case 2:{
            const int arraySize = 5;
            int arr1[arraySize];
            int arr2[arraySize];
            char input[10];

            for (int i = 0; i < 5; i++) {
                bool valid_input = false;

                while (!valid_input) {
                    cin >> input;

                    bool is_int = true;
                    int j = 0;
                    if (input[0] == '-' || input[0] == '+') {
                        j++;
                    }
                    while (input[j] != '\0') {
                        if (input[j] < '0' || input[j] > '9') {
                            is_int = false;
                            break;
                        }
                        j++;
                    }

                    if (is_int) {
                        arr1[i] = atoi(input);
                        valid_input = true;
                    } 
                    else {
                        cout << "Invalid input." << endl;
                    }
                }
            }

            for (int i = 0; i < 5; i++) {
                bool valid_input = false;

                while (!valid_input) {
                    cin >> input;

                    bool is_int = true;
                    int j = 0;
                    if (input[0] == '-' || input[0] == '+') {
                        j++;
                    }
                    while (input[j] != '\0') {
                        if (input[j] < '0' || input[j] > '9') {
                            is_int = false;
                            break;
                        }
                        j++;
                    }

                    if (is_int) {
                        arr2[i] = atoi(input);
                        valid_input = true;
                    } 
                    else {
                        cout << "Invalid input." << endl;
                    }
                }
            }

            for (int i = 0; i < 4; i++) {
                for (int j = i + 1; j < 5; j++) {
                    if (arr1[i] > arr1[j]) {
                        int temp = arr1[i];
                        arr1[i] = arr1[j];
                        arr1[j] = temp;
                    }

                    if (arr2[i] > arr2[j]) {
                        int temp = arr2[i];
                        arr2[i] = arr2[j];
                        arr2[j] = temp;
                    }
                }
            }

            bool equal = true;
            for (int i = 0; i < 5; i++) {
                if (arr1[i] != arr2[i]) {
                    equal = false;
                    break;
                }
            }

            if (equal) {
                cout << "Equal." << endl;
            } 
            else {
                cout << "Different." << endl;
            }
            break;
            }
        case 3:{
            char romanNumber[50];
            cin >> romanNumber;

            int arabicNumber = 0;
            int previousValue = 0;
            int currentValue = 0;
            int maxLength = 0;
            int count = 0;

            for (int i = 0; romanNumber[i] != '\0'; i++) {
                currentValue = romanToArabic(romanNumber[i]);

                if (currentValue == -1) {
                    cout << "Wrong input data." << endl;
                    return 1;
                }

                if (previousValue < currentValue) {
                    if (previousValue == 0) {
                        previousValue = currentValue;
                        count++;
                    }
                    else if (currentValue / previousValue == 5 || currentValue / previousValue == 10) {
                        arabicNumber += (currentValue - previousValue);
                        previousValue = 0;
                        count = 0;
                    }
                    else {
                        cout << "Wrong input data." << endl;
                        return 1;
                    }
                }
                else {
                    if (previousValue == currentValue) {
                        count++;
                        if (count > maxLength) {
                            maxLength = count;
                        }
                    }
                    else {
                        arabicNumber += (previousValue * count);
                        previousValue = currentValue;
                        count = 1;
                    }
                }
            }

            if (count > maxLength) {
                maxLength = count;
            }

            arabicNumber += (previousValue * count);

            if (arabicNumber < 1 || arabicNumber > 3999) {
                cout << "Wrong input data." << endl;
                return 1;
            }

            if (maxLength > 3) {
                cout << "Wrong input data." << endl;
                return 1;
            }

            cout << "Converted " << romanNumber << " to " << arabicNumber << "." << endl;

            break;
            }
        default:{
            cout << "Wrong task number." << endl;
            break;
            }
    }
    return 0;
}