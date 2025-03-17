#include "Complex.h"

Complex::Complex() : Re(0), Im(0) {}

Complex::Complex(double Re, double Im) : Re(Re), Im(Im) {}

Complex::operator double() const{ return sqrt(Re*Re + Im*Im); }

Complex::operator std::string() const{
    std::ostringstream os;
    os << Re << (Im < 0 ? "" : "+") << Im << "i";
    return os.str();
}

Complex Complex::operator+(const Complex& other) const{ return{Re+other.Re, Im+other.Im}; }

Complex Complex::operator-(const Complex& other) const{ return{Re-other.Re, Im-other.Im}; }

Complex Complex::operator*(const Complex& other) const{
    return{Re*other.Re-Im*other.Im, Re*other.Im+Im*other.Re};
}

Complex Complex::operator/(const Complex& other) const{
    double denominator = 1.0/(other.Re*other.Re + other.Im*other.Im);

    return {(Re*other.Re+Im*other.Im)*denominator, (Im*other.Re-Re*other.Im)*denominator};
}

double Complex::operator()(const std::function<double(const Complex&)>& f) const{
    return f(*this);
}

std::ostream& operator<<(std::ostream& os, const Complex& k){
    os << std::string(k);
    return os;
}