#include <iostream>
using namespace std;


 void sortArray(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}   

bool areEqual(int arr1[], int arr2[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

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
            int arr1[5], arr2[5];

            for (int i = 0; i < 5; i++) {
                cin >> arr1[i];
            }

            for (int i = 0; i < 5; i++) {
                cin >> arr2[i];
            }

            sortArray(arr1, 5);
            sortArray(arr2, 5);

            if (areEqual(arr1, arr2, 5)) {
                cout << "Equal.\n";
            } else {
                cout << "Different.\n";
            }
            
            break;
            }
        case 3:{
            char romanNumber[50];
            cin >> romanNumber;
            char previousLetter = ' ';
            char currentLetter = ' ';
            char nextLetter = ' ';
            bool isWrong = false;

            for (int i = 0; romanNumber[i] != '\0'; i++) {
                if (i > 0) {
                    previousLetter = romanNumber[i-1];
                }
                currentLetter = romanNumber[i];
                nextLetter = romanNumber[i+1];

                if (previousLetter == currentLetter && (nextLetter == 'V' || nextLetter == 'X' || nextLetter == 'L' || nextLetter == 'C' || nextLetter == 'D' || nextLetter == 'M')) {
                    cout << "Wrong input data.";
                    isWrong = true;
                    break;
                }
            }

            int arabicNumber = 0;
            int previousValue = 0;
            int currentValue = 0;
            int maxLength = 0;
            int count = 0;

            if (!isWrong) { 
                for (int i = 0; romanNumber[i] != '\0'; i++) {
                    currentValue = romanToArabic(romanNumber[i]);

                    if (currentValue == -1) {
                        cout << "Wrong input data." << endl;
                        break;
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
                            break;
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
                    break;
                }

                if (maxLength > 3) {
                    cout << "Wrong input data." << endl;
                    break;
                }

                cout << "Converted " << romanNumber << " to " << arabicNumber << "." << endl;
            }
            break;
            }
        default:{
            cout << "Wrong task number." << endl;
            break;
            }
    }
    return 0;
}