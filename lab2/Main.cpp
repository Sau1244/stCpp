/*
Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

Celem zadania jest zdefiniowanie klasy Complex, która reprezentuje liczby zespolone
w postaci a + bi, gdzie a to część rzeczywista, a b to część urojona.

Klasa powinna wspierać:
 * Konstruktor domyślny (ustawiający 0 + 0i) oraz konstruktor z dwoma argumentami (a, b).
 * Podstawowe operacje arytmetyczne: operator +, operator -, operator * oraz operator /,
   zgodnie z regułami algebry zespolonych.
 * Operator wyjścia << umożliwiający wypisywanie liczby w formacie "a + bi" (lub "a - bi").
 * Konwersje użytkowania:
   - Niejawna konwersja umożliwiająca rzutowanie Complex na double, która zwraca moduł liczby zespolonej 
     (sqrt(a² + b²)).
   - Jawna konwersja (explicit) pozwalająca na rzutowanie Complex na std::string, zwracająca tekstową 
     reprezentację liczby, np. "a + bi" lub "a - bi".
 * (Opcjonalnie) Operator funkcyjny operator(), który przyjmie funkcję typu std::function<double(const Complex&)>
   i zwróci wynik jej wywołania z bieżącym obiektem. (Przyda się na przyszłość)

Dodatkowe wymagania:
 - Pliku Main.cpp nie wolno modyfikowac.
 - Kody źródłowe muszą znajdować się w katalogu, do którego nikt oprócz właściciela nie ma praw dostępu.
 - Rozwiązanie (czyli dodane pliki oraz Main.cpp) należy wgrać do UPEL jako archiwum tar.gz.
   UWAGA: archiwum powinno zawierać katalog z zadaniem, np. lab03/, a nie katalog build/.
 - Kod powinien być przyjazny dla programisty, czytelny i zgodny z zasadą DRY.
 - Podczas wykonywania zadania nie wolno korzystać z internetu, notatek ani żadnych innych materiałów.

*/

#include <iostream>
#include <iomanip>
#include <string>
#include "Complex.h"

int main() {
    Complex c1;              // Domyślna liczba zespolona: 0 + 0i
    Complex c2(3, 4);        // Reprezentuje 3 + 4i
    Complex c3(1, -2);       // Reprezentuje 1 - 2i

    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c3: " << c3 << std::endl;

    // Niejawna konwersja do double – moduł liczby zespolonej
    double m = c2;
    std::cout << "Moduł c2: " << m << std::endl;

    // Jawna konwersja do std::string – tekstowa reprezentacja liczby
    std::string s = static_cast<std::string>(c3);
    std::cout << "Reprezentacja c3: " << s << std::endl;

    // Przykładowe operacje arytmetyczne:
    Complex sum = c2 + c3;
    std::cout << "c2 + c3: " << sum << std::endl;

    Complex prod = c2 * c3;
    std::cout << "c2 * c3: " << prod << std::endl;

    return 0;
}


// Spodziewany Output:

// c1: 0 + 0i
// c2: 3 + 4i
// c3: 1 - 2i
// Moduł c2: 5
// Reprezentacja c3: 1 - 2i
// c2 + c3: 4 + 2i
// c2 * c3: 11 - 2i