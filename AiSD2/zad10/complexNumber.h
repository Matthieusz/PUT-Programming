#include <cmath>
#include <iostream>
using namespace std;

class ComplexNumber {
private:
    float real;
    float imag;

public:
    ComplexNumber(float r, float i);

    float modulus() const;

    bool operator<(const ComplexNumber& other) const;

    bool operator==(const ComplexNumber& other) const;

    friend ostream& operator<<(std::ostream& os, const ComplexNumber& cn);
};
