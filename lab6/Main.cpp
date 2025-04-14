// Zadanie:

// Celem zadania jest praktyczne przećwiczenie:
// - semantyki przenoszenia (move semantics),
// - użycia inteligentnych wskaźników (std::unique_ptr),
// - wirtualnych funkcji oraz polimorfizmu.

// Kontekst:

// Twoim zadaniem jest stworzenie uproszczonego systemu zarządzania zwierzętami w zoo.

// 1. Abstrakcyjna klasa bazowa Animal z metodą wirtualną makeSound(), która wyświetla dźwięk wydawany przez zwierzę.

// 2. Klasy pochodne:
//    - Lion (np. ryczy w określony sposób),
//    - Monkey (np. wydaje charakterystyczne dźwięki).

// 3. Klasa Zoo:
//    - zarządza kolekcją zwierząt za pomocą std::unique_ptr,
//    - posiada metodę pozwalającą na wywołanie dźwięku zwierzęcia o wskazanym indeksie.

// Wszystkie klasy muszą poprawnie zarządzać pamięcią dynamiczną oraz obsługiwać kopiowanie i przenoszenie.

// PRZYPOMNIENIE ZASAD NA zajęciach panujących:
//   - Zasady oceny:
//       Dokumentacja - 1 pkt. 
//       Poprawna kompilacja (bez ostrzeżeń) - 2 pkt. 
//       Poprawne wykonanie (odpowiednie wyjście, brak wycieków pamięci itp.) - 3 pkt. 
//       Ocena kodu (pod względem projektowym, zgodności z OOP, przejrzystości oraz sposobu implantacji) - maks. 4 pkt.
//   - Nie można korzystać z pomocy osób trzecich, w tym z internetu.
//   - Nie można korzystać z pomocy sztucznej inteligencji (AI).
//   - Nie można korzystać z pomocy wtyczek do IDE, które podpowiadają kod, generują kod, podpowiadają błędy itp.
//   - Każda osoba powinna umieścić swój kod w osobnym katalogu, który nie może być dostępny do odczytu dla innych osób w sieci!
//   - Pliku Main.cpp nie wolno modyfikowac.
//   - Kody zródłowe muszą znajdować się w katalogu, do którego nikt oprócz własника nie ma praw dostępu.
//   - Rozwiązanie (czyli dodane pliki oraz Main.cpp) należy wgrąć do UPEL jako archiwum tar.gz.
//     UWAGA: archiwum powinno zawierać katalog z zadaniem, np. lab03/, a nie katalog build/.
//   - Kod powinien być przyjazny dla programisty, czytelny i zgodny z zasadą DRY.

// PAKOWANIE DO TAR.GZ:  
//    Dodaj do ~/.bashrc następujący alias:
//    alias packdir='f(){ dir=${1%/}; base=${dir##*/}; parent=$(realpath "$(dirname "$dir")"); tar -czvf "$base.tar.gz" -C "$parent" "$base"; }; f'
//    Użycie aliasu packdir:
//    packdir <ścieżka_do_katalogu_z_zadaniem>
//    Przykład: packdir ~/cpp/2024_2025/cpp2/jakub/Lab05/




#include "Zoo.h"
#include "Animal.h"
#include "Lion.h"
#include "Monkey.h"
#include <memory>

int main() {
    std::cout << "--- Zoo Animals ---\n";

    Zoo cityZoo;
    cityZoo.addAnimal(std::make_unique<Lion>("Simba"));
    cityZoo.addAnimal(std::make_unique<Monkey>("George"));

    cityZoo.makeAnimalSound(0);
    cityZoo.makeAnimalSound(1);

    std::cout << "\n--- Copied Zoo ---\n";
    Zoo copiedZoo = cityZoo;
    copiedZoo.addAnimal(std::make_unique<Lion>("Nala"));
    copiedZoo.makeAnimalSound(2);

    std::cout << "\n--- Moved Zoo ---\n";
    Zoo movedZoo = std::move(cityZoo);
    movedZoo.makeAnimalSound(0);

    std::cout << "\n--- Zoo after Move ---\n";
    cityZoo.makeAnimalSound(0);  // Powinno być obsłużone (brak zwierząt)
    movedZoo.makeAnimalSound(1);

    return 0;
}

/* Oczekiwany wynik programu:

--- Zoo Animals ---
Lion Simba roars: ROOAAAR!
Monkey George says: Ooh-ooh-aah-aah!

--- Copied Zoo ---
Lion Nala roars: ROOAAAR!

--- Moved Zoo ---
Lion Simba roars: ROOAAAR!

--- Zoo after Move ---
Zoo is empty, no animals to make sounds!
Monkey George says: Ooh-ooh-aah-aah!

Zoo destroyed.
Zoo destroyed.
Zoo destroyed.
*/
