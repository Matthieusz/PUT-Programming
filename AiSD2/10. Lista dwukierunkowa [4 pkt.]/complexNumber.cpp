#include "complexNumber.h"

ComplexNumber::ComplexNumber(float r = 0, float i = 0) : real(r), imag(i) {}

float ComplexNumber::modulus() const {
    return sqrt(real*real + imag*imag);
}

bool ComplexNumber::operator<(const ComplexNumber& other) const {
    if (modulus() != other.modulus()) {
        return modulus() < other.modulus();
    }
    if (real != other.real) {
        return real < other.real;
    }
    return imag < other.imag;
}

bool ComplexNumber::operator==(const ComplexNumber& other) const {
    return real == other.real && imag == other.imag;
}

ostream& operator<<(ostream& os, const ComplexNumber& cn) {
    os << cn.real;
    if (cn.imag >= 0) os << "+";
    if (cn.imag != 0) os << cn.imag << "i";
    return os;
}
