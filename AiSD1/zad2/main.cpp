#include <iostream>
using namespace std;

int main () {
    int program;
    float result;
    float firstNumber, secondNumber, thirdNumber, fourthNumber;
    cin >> program;
    switch (program) {
        case 1:
            cin >> firstNumber >> secondNumber >> thirdNumber >> fourthNumber;
            result = (firstNumber + secondNumber + thirdNumber + fourthNumber)/4;
            cout << result << endl;
            break;
        case 2:
            cin >> firstNumber >> secondNumber;
            if (firstNumber < 0 || secondNumber < 0) {
                cout << "NaN";
                break;
            }
            result = (firstNumber*secondNumber)/2;
            cout << result << endl;
            break;
        case 3:
            int operacja;
            float a,b;
            cin >> operacja;
            cin >> a >> b;
            switch (operacja) {
                case 1:
                    result = a + b;
                    cout << result;
                    break;
                case 2:
                    result = a - b;
                    cout << result;
                    break;
                case 3:
                    result = a * b;
                    cout << result;
                    break;
                case 4:
                    result = a / b;
                    if (b == 0)
                        cout << "NaN";
                        break;
                    cout << result;
                    break;
                case 5:
                    result = (static_cast<int>(a) % static_cast<int>(b));
                    cout << result;
                    break;
                default:
                    cout << "Wrong task number.";
                    break;
            }
            break;
        default:
            cout << "Wrong task number." << endl;
    }
    return 0;
}