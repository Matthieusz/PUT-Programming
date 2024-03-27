#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <vector>
#include "vector.h"
using namespace std;

class Matrix {
private:
    std::vector<std::vector<int>> data;
public:
    Matrix(int m, int n) : data(m, std::vector<int>(n)) {}

    std::vector<int>& operator[](int index) {
        return data[index];
    }

    bool operator==(const Matrix& other) const {
        if (data.size() != other.data.size()) {
            return false;
        }

        for (size_t i = 0; i < data.size(); i++) {
            if (data[i].size() != other.data[i].size()) {
                return false;
            }
        }
        for (size_t i = 0; i < data.size(); i++) {
            for (size_t j = 0; j < data[0].size(); j++) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    

    Matrix operator*(const Matrix& other) const {
        int m = data.size();
        int n = data[0].size();
        int p = other.data[0].size();

        if (n != other.data.size()) {
            throw std::invalid_argument("Dimensions do not match for matrix multiplication");
        }

        Matrix result(m, p);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < p; j++) {
                for (int k = 0; k < n; k++) {
                    result[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix& operator*=(int k) {
        for (auto& row : data) {
            for (auto& element : row) {
                element *= k;
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Matrix& matrix);
};

ostream& operator<<(ostream& os, const Matrix& matrix) {
    int m = matrix.data.size();
    int n = matrix.data[0].size();

    os << "Matrix (" << m << "x" << n << "):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            os << matrix.data[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

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
}

void zad7() {
    int m, n, p;
    cout << "Podaj wymiary macierzy A (m x n): ";
    cin >> m >> n;
    Matrix A(m, n);
    cout << "Podaj elementy macierzy A:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    cout << "Podaj wymiary macierzy B (n x p): ";
    cin >> n >> p;
    Matrix B(n, p);
    cout << "Podaj elementy macierzy B:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> B[i][j];
        }
    }
    cout << "A:" << endl << A << endl;
    cout << "B:" << endl << B << endl;
    cout << "A == B: " << (A == B) << endl;
    cout << endl;
    try {
        Matrix C = A * B;
        cout << "A * B:" << endl << C << endl;
    } catch (const std::invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    cout << "A * 2:" << endl << (A *= 2) << endl;
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
            zad7();
            break;
        default:
            cout << "Nie ma takiego zadania" << endl;
            break;
        }
    } while (true);
    return 0;
}