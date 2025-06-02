/*
Zadanie polega na implementacji systemu Ranking, który przechowuje informacje 
na temat graczy i ich wyników punktowych z gier planszowych. Każdy gracz ma:
 - nazwę (jeden string),
 - listę wyników (vector<int>).

Do reprezentacji danych gracza należy użyć std::pair<string, vector<int>>.

Wymagania:
* Klasa/serwis Ranking operuje na kontenerze ScoreList, który jest aliasem 
  do kontenera sekwencyjnego (std::vector), przechowującego obiekty typu ScoreEntry
* Typ ScoreEntry powinien być zdefiniowany za pomocą aliasu using i wskazywać na std::pair
* W kodzie należy wykorzystać value_type oraz iterator do przechodzenia po ScoreList
* Do wyszukiwania gracza po nazwie należy użyć algorytmu std::find_if
  https://en.cppreference.com/w/cpp/algorithm/find
* Funkcje wypisujące dane powinny używać iteratorów, a nie indeksów
* Program powinien kompilować się bez ostrzeżeń, być czytelny i zgodny z zasadą DRY (Don't Repeat Yourself)
* Zwróć uwagę na czytelność wypisywania wyników – np. wypisz listę w formacie:
  Gracz: Imie, Wyniki: [x, y, z]

Plik Main.cpp nie może być modyfikowany.
Struktura programu powinna być oparta o plik CMakeLists.txt.
Wszystkie brakujące elementy należy zaimplementować w Ranking.cpp i Ranking.hpp.
*/

#include "Ranking.h"
#include <iostream>

int main() {
    ScoreList scores;

    addPlayer(scores, {"Ala", {4, 5, 3}});
    addPlayer(scores, {"Bartek", {2, 2, 4}});
    addPlayer(scores, {"Celina", {5, 5, 5}});

    printAll(scores);

    std::cout << "\n-- Szukam gracza o nazwie 'Ala' --\n";
    auto* found = findPlayer(scores, "Ala");
    if (found) {
        printSingle(*found);
    } else {
        std::cout << "Nie znaleziono gracza!\n";
    }

    return 0;
}

// Output:

// Gracz: Ala, Wyniki: [4, 5, 3]
// Gracz: Bartek, Wyniki: [2, 2, 4]
// Gracz: Celina, Wyniki: [5, 5, 5]

// -- Szukam gracza o nazwie 'Ala' --
// Gracz: Ala, Wyniki: [4, 5, 3]

