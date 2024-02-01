#include <iostream>
#include <cmath>
#include "complexNumber.h"
#include "linkedList.h"

using namespace std;

int main() {
    LinkedList<ComplexNumber> list;
    int M, N;
    float real, imag;

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> real >> imag;
        list.add(ComplexNumber(real, imag));
    }

    cout << list;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> real >> imag;
        list.remove(ComplexNumber(real, imag));
    }

    cout << list;

    return 0;
}