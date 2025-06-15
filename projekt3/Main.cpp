// Zadanie: Szablon klasy BetterVector
//
// Napisz szablon klasy `BetterVector<T>`, który działa jak uproszczona wersja std::data.
//
// Wymagane funkcjonalności:
// - Konstruktor domyślny
// - Destruktor
// - `void push_back(const T&)` – dodaje element na koniec
// - `void pop_back()` – usuwa ostatni element (jeśli istnieje)
// - `T& operator[](size_t)` – dostęp do elementu przez operator []
// - `size_t size() const` – zwraca liczbę elementów
// - `bool empty() const` – sprawdza, czy kontener jest pusty
//
// UWAGI:
// - Przechowywanie elementów możesz zaimplementować przez dynamicznie alokowaną tablicę,
//   która automatycznie zwiększa rozmiar (np. podwaja się przy przepełnieniu).
// - Nie używaj std::data ani innych gotowych kontenerów STL do przechowywania danych.
//
// Dodatkowe uwagi:
// - Zadbaj o poprawne zarządzanie pamięcią (reguła 3/5).
// - Zaplanuj kod tak, by dało się go łatwo rozbudować w przyszłości (np. iteratory, insert, sort).
//


#include <iostream>
#include <string>
#include <cassert>
#include "BetterVector.h"

int main() {
    BetterVector<int> vi;
    assert(vi.empty());
    vi.push_back(42);
    vi.push_back(13);
    assert(vi.size() == 2);
    std::cout << "Pierwszy element: " << vi[0] << "\n";
    vi.pop_back();
    assert(vi.size() == 1);

    BetterVector<std::string> vs;
    vs.push_back("Hello");
    vs.push_back("World");
    std::cout << "Drugi string: " << vs[1] << "\n";

    std::cout << "Wszystkie testy przeszły pomyślnie.\n";
}