#include "Complex.h"

Complex::Complex() : Re(0), Im(0) {}

Complex::Complex(double Re, double Im) : Re(Re), Im(Im) {}

Complex::operator double() const{ return sqrt(Re*Re + Im*Im); }

Complex::operator std::string() const{
    std::string str = std::to_string(Re);
    str += (Im < 0 ? "" : "+") + std::to_string(Im) + "i";
    return str;
}

Complex Complex::operator+(const Complex& other) const{ return{Re+other.Re, Im+other.Im}; }

Complex Complex::operator-(const Complex& other) const{ return{Re-other.Re, Im-other.Im}; }

Complex Complex::operator*(const Complex& other) const{
    return{Re*other.Re-Im*other.Im, Re*other.Im+Im*other.Re};
}

Complex Complex::operator/(const Complex& other) const{
    double denominator = other.Re*other.Re + other.Im*other.Im;
    double numeratorRe = Re*other.Re + Im*other.Im;
    double numeratorIm = Im*other.Re - Re*other.Im;

    return {numeratorRe/denominator, numeratorIm/denominator};
}

double Complex::operator()(const std::function<double(const Complex&)>& f) const{
    return f(*this);
}

std::ostream& operator<<(std::ostream& os, const Complex& k){
    os << k.Re << (k.Im < 0 ? "" : "+") << k.Im << "i";
    return os;
}