#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>
#include <sstream>
#include <functional>

class Complex{
private:
    double Re;
    double Im;
public:
    //konstruktor domyślny
    Complex();

    //konstruktor przyjmujący (Re, Im)
    Complex(double Re, double Im);

    //niejawna konwersja zwracająca moduł liczby zespolonej
    operator double() const;

    //jawna konwersja zwracająca tekstową reprezentację liczby zespolonej
    explicit operator std::string() const;

    //podstawowe operacje arytmetyczne
    //operator dodawania +
    Complex operator+(const Complex& other) const;
    //operator odejmowania -
    Complex operator-(const Complex& other) const;
    //operator mnożenia *
    Complex operator*(const Complex& other) const;
    //operator dzielenia /
    Complex operator/(const Complex& other) const;

    //operator funkcyjny zwraca wynik wywołania z bieżącym obiektem
    double operator()(const std::function<double(const Complex&)>& f) const;

    //przeciążenie operatora wyjścia <<
    friend std::ostream& operator<<(std::ostream& os, const Complex& k);
};

#endif