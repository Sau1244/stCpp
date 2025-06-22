// Rozbudowa klasy better_vector — część 2
//
// Twoim zadaniem jest dalsze rozwinięcie klasy better_vector napisanej w poprzednim zadaniu.
// Poniżej znajdziesz dokładny opis nowych funkcjonalności, które musisz zaimplementować:
//
// 1. Nowe metody zarządzania danymi:
//    - clear()
//      Usuwa wszystkie elementy z wektora. Wektor powinien być pusty (size() == 0), ale zaalokowana pamięć nie musi być zwalniana.
//
//    - front() i back()
//      Zwracają odpowiednio pierwszy i ostatni element. Jeśli wektor jest pusty, zachowanie jest niezdefiniowane (nie musisz tego obsługiwać).
//
//    - reserve(size_t new_capacity)
//      Zwiększa pojemność wektora do co najmniej wartości new_capacity, jeżeli aktualna pojemność jest mniejsza.
//
// 2. Metoda szablonowa emplace_back(Args&&... args):
//      Metoda ta umożliwia stworzenie nowego elementu bezpośrednio na końcu wektora za pomocą konstruktora klasy T.
//      Przykład użycia:
//        better_vector<std::pair<int, std::string>> vp;
//        vp.emplace_back(42, "hello"); // para będzie skonstruowana bezpośrednio w pamięci wektora.
//
// 3. Operacje matematyczne na wektorach:
//    - operator+(const better_vector& other)
//      Dodawanie dwóch wektorów tego samego typu (element po elemencie). Operacja jest poprawna tylko gdy oba wektory mają tę samą długość.
//
//    - operator-(const better_vector& other)
//      Odejmowanie element po elemencie, analogiczne ograniczenie jak dla operatora+.
//
//    - operator*(const Scalar& scalar)
//      Mnożenie wektora przez skalar. Każdy element wektora ma być pomnożony przez podaną wartość skalara.
//      Ogranicz użycie tej metody tylko do typów arytmetycznych (użyj std::enable_if oraz std::is_arithmetic).
//
// 4. Testowanie:
//    Do weryfikacji poprawności swojego rozwiązania użyj funkcji assert().
//    Funkcja ta sprawdza logiczny warunek i kończy działanie programu, jeśli ten warunek jest fałszywy.
//    Przykład użycia assert:
//      better_vector<int> v1 {1,2,3};
//      better_vector<int> v2 {4,5,6};
//      auto v3 = v1 + v2;
//      assert(v3.size() == 3);
//      assert(v3[0] == 5 && v3[1] == 7 && v3[2] == 9);
//
// UWAGI:
// - Pamiętaj o obsłudze błędów, szczególnie w operacjach matematycznych (rozmiar wektorów musi się zgadzać!).
// - Staraj się jak najwięcej testować swoje rozwiązanie. Poprawność implementacji ma być weryfikowana właśnie za pomocą assertów.

#include <iostream>
#include <cassert>
#include "BetterVector.h"

int main() {

    BetterVector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    BetterVector<int> v2;
    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);

    std::cout << "dodawanie wektorów\n";
    auto v3 = v1 + v2;
    std::cout << "v1: " << v1[0] << ";" << v1[1] << ";" << v1[2] << std::endl;
    std::cout << "v2: " << v2[0] << ";" << v2[1] << ";" << v2[2] << std::endl;
    std::cout << "v3: " << v3[0] << ";" << v3[1] << ";" << v3[2] << std::endl;
    assert(v3.size() == 3);
    assert(v3[0] == 5 && v3[1] == 7 && v3[2] == 9);

    std::cout << "Mnożenie wektorów przez skalar\n";
    auto v4 = v1 * 2;
    std::cout << "v1: " << v1[0] << ";" << v1[1] << ";" << v1[2] << std::endl;
    std::cout << "v4: " << v4[0] << ";" << v4[1] << ";" << v4[2] << std::endl;
    assert(v4.size() == 3);
    assert(v4[0] == 2 && v4[1] == 4 && v4[2] == 6);

    std::cout << "Odejmowanie wektorów\n";
    auto v5 = v2 - v1;
    std::cout << "v1: " << v1[0] << ";" << v1[1] << ";" << v1[2] << std::endl;
    std::cout << "v2: " << v2[0] << ";" << v2[1] << ";" << v2[2] << std::endl;
    std::cout << "v5: " << v5[0] << ";" << v5[1] << ";" << v5[2] << std::endl;
    assert(v5.size() == 3);
    assert(v5[0] == 3 && v5[1] == 3 && v5[2] == 3);

    v1.clear();
    assert(v1.empty());

    v2.reserve(10);
    //test sprawdzający czy pamięc jest zaalokowana
    assert(v2.capacity() == 10);
    v2.emplace_back(7);
    assert(v2.back() == 7);

    std::cout << "Wszystkie testy przeszły poprawnie!\n";
}


/*
Spodziewany output:
Wszystkie testy przeszły poprawnie!
*/