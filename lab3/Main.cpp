// Proszę dopisać brakujący kod oraz dodać nowe pliki w taki sposób, aby program kompilował się, 
// wykonywał poprawnie, a wynik jego działania był identyczny jak przedstawiony na końcu pliku `Main.cpp`.

//  Celem zadania  jest implementacja specjalnej listy (`NegList`) przechowującej wartości typu `int`. 
//  Lista powinna działać analogicznie do listy w języku Python, umożliwiając dostęp do elementów 
//  za pomocą operatora `[]` z ujemnymi indeksami:
// - Pierwszy dodany element powinien być dostępny przez indeks `-1`, drugi przez `-2`, trzeci przez `-3` itd.
// - Lista „rośnie do tyłu”, co oznacza, że kolejne dodawane elementy mają coraz bardziej ujemne indeksy.

// Dodatkowo należy zaimplementować klasę `ListInspector`, która umożliwia inspekcję listy i zwraca jej 
// aktualny stan (np. rozmiar listy) jako ciąg znaków.

//   Wymagania dotyczące struktury projektu:
// - Każda klasa powinna być zdefiniowana w osobnym pliku nagłówkowym (.h) oraz źródłowym (.cpp).
// - Struktura projektu powinna wyglądać następująco:
//   - Deklaracje klas (`NegList`, `ListInspector`) w katalogu `include/`
//   - Implementacje klas rozbite na oddzielne pliki źródłowe w katalogu `src/`:
//     - `NegList.cpp` – konstruktor, destruktor, `getSize()`, `setInspector()`
//     - `NegList_append.cpp` – metoda `append()`
//     - `NegList_index.cpp` – operator `[]` dla indeksowania
//     - `NegList_pop.cpp` – metoda `pop()`
//     - `ListInspector.cpp` – metoda `inspect()`
//     - (Opcjonalnie) dodatkowe funkcje pomocnicze w pliku `Utils.h` oraz `Utils.cpp`
// - Uważaj na niebezpieczeństwo cyklicznych zależności.

//   Dodatkowe wymagania:
// - Zabronione jest używanie standardowych kontenerów (`std::vector`, `std::array`). 
//   Zarządzanie pamięcią musi być wykonywane ręcznie, bez wycieków.
// - Nie wolno modyfikować plików `Main.cpp` oraz `CMakeLists.txt`.
// - Gotowe rozwiązanie (pliki źródłowe oraz `Main.cpp`) należy dostarczyć na platformę UPEL w postaci 
//   archiwum `.tar.gz` zawierającego katalog z zadaniem (np. `lab03/`). Archiwum nie powinno zawierać katalogu `build/`.
// - Kod musi być czytelny, zgodny z zasadami dobrego stylu oraz spełniać regułę D.R.Y. (Don't Repeat Yourself).
// - Wszystkie pliki źródłowe powinny znajdować się w katalogu z ograniczonym dostępem wyłącznie dla właściciela.
// - Jeśli podczas kompilacji zostanie ustawiona flaga `ENABLE_ERROR_TEST`, przypisanie wartości niezgodnej z typem 
// `int` do elementu listy powinno skutkować błędem kompilacji.
// - Podczas wykonywania zadania zabronione jest korzystanie z internetu, notatek lub innych materiałów pomocniczych.



#include "NegList.h"
#include "ListInspector.h"
#include <iostream>

int main() {
    NegList myList;

    myList.append(100);
    myList.append(200);
    myList.append(300);

    ListInspector inspector;
    myList.setInspector(&inspector);

    std::cout << "Element o indeksie -1: " << myList[-1] << "\n"; // Oczekiwane: 100
    std::cout << "Element o indeksie -2: " << myList[-2] << "\n"; // Oczekiwane: 200
    std::cout << "Element o indeksie -3: " << myList[-3] << "\n"; // Oczekiwane: 300

    std::cout << "Status listy: " << inspector.inspect(myList) << "\n"; // Oczekiwane: "NegList size: 3"

    myList.pop(); // Usunięcie ostatniego elementu (300)

    #ifdef ENABLE_ERROR_TEST
    // Poniższa linia powinna spowodować błąd kompilacji,
    // ponieważ próbujemy przypisać wartość typu const char* do int.
    myList[-1] = "Error";  
    #endif

    std::cout << "Po operacji pop:\n";
    std::cout << "Element o indeksie -1: " << myList[-1] << "\n"; // Oczekiwane: 100
    std::cout << "Element o indeksie -2: " << myList[-2] << "\n"; // Oczekiwane: 200
    std::cout << "Status listy: " << inspector.inspect(myList) << "\n"; // Oczekiwane: "NegList size: 2"

    return 0;
}

/* Oczekiwany wynik działania programu:
Element o indeksie -1: 100
Element o indeksie -2: 200
Element o indeksie -3: 300
Status listy: NegList size: 3
Po operacji pop:
Element o indeksie -1: 100
Element o indeksie -2: 200
Status listy: NegList size: 2
*/
