/*

#### Celem projektu
jest implementacja własnego systemu zarządzania drużynami Pokémonów przy użyciu klas:
Trainer, Team oraz Pokemon.
Dane powinny być przechowywane w listach dwukierunkowych, bez użycia kontenerów STL,
takich jak `std::vector` czy `std::list`.

--------------------------------------------------------------------------------------------
## Lista Dwukierunkowa – Definicja i Implementacja
Lista dwukierunkowa to **dynamiczna struktura danych**, w której każdy element (węzeł) zawiera:
1. **Wskaźnik na poprzedni element** (`prev`)
2. **Dane** (np. `Pokemon` lub `Team`)
3. **Wskaźnik na następny element** (`next`)

### Jak działa lista dwukierunkowa w naszym projekcie?
#### **Dodawanie elementu na końcu listy**
1. Tworzymy nowy węzeł (`newNode`).
2. Jeśli lista jest pusta – ustawiamy `m_head = m_tail = newNode`.
3. Jeśli nie – podpinamy `newNode` do `m_tail`:
   m_tail->next = newNode;
   newNode->prev = m_tail;
   m_tail = newNode;

#### Iteracja po liście
// Od początku do końca:
PokemonNode* current = m_head;
while (current) {
    current->pokemon.printInfo();
    current = current->next;
}
// Od końca do początku:
PokemonNode* current = m_tail;
while (current) {
    current->pokemon.printInfo();
    current = current->prev;
}

--------------------------------------------------------------------------------------------

## Struktura i Zależności Klas w projekcie

### Klasa `Pokemon`
Reprezentuje pojedynczego Pokémona należącego do drużyny (`Team`).
#### **Atrybuty:**
- `m_name` – nazwa Pokémona
- `m_type` – typ Pokémona (np. Fire, Water, Grass)

#### **Metody:**
- Konstruktor do inicjalizacji Pokémona
- `printInfo()` – wypisuje informacje o Pokémonie

---
#### Do klasy Pokemon odnosi się struktura `PokemonNode` (Węzeł listy)

---

### Klasa `Team` (Drużyna)
Reprezentuje drużynę Pokémonów. Przechowuje Pokémony w dwukierunkowej liście.

#### **Atrybuty:**
- `m_name` – nazwa drużyny
- `m_head` – wskaźnik na pierwszy element listy `PokemonNode`
- `m_tail` – wskaźnik na ostatni element listy `PokemonNode`

#### **Metody:**
- Konstruktor inicjalizujący drużynę
- **`addPokemon(Pokemon&)`** – dodaje Pokémona do drużyny
- **`removePokemon(std::string name)`** – usuwa Pokémona z drużyny
- **`operator[](int index)`** – dostęp do Pokémona po indeksie
- **`printPokemonsForward()`** – iteracja od początku do końca
- **`printPokemonsBackward()`** – iteracja od końca do początku
- **Destruktor** – zwalnia pamięć usuwając całą listę

---
#### Do klasy Team odnosi się struktura `TeamNode` (Węzeł listy)
---

### Klasa `Trainer` (Trener)
Reprezentuje trenera Pokémonów, który zarządza kilkoma drużynami.

#### **Atrybuty:**
- `m_name` – nazwa trenera
- `m_head` – wskaźnik na pierwszy element listy `TeamNode`
- `m_tail` – wskaźnik na ostatni element listy `TeamNode`

#### **Metody:**
- Konstruktor inicjalizujący trenera
- **`addTeam(Team&)`** – dodaje drużynę do listy drużyn trenera
- **`printTeams()`** – wypisuje wszystkie drużyny trenera
- **Destruktor** – zwalnia pamięć usuwając całą listę
*/

#include "Trainer.h"
#include "Team.h"
#include "Pokemon.h"
#include <iostream>

int main() {
    Trainer ash("Ash Ketchum");

    Team teamA("Kanto Team");
    Team teamB("Johto Team");

    ash.addTeam(teamA);
    ash.addTeam(teamB);

    Pokemon p1("Pikachu", "Electric");
    Pokemon p2("Charizard", "Fire");
    Pokemon p3("Bulbasaur", "Grass");
    Pokemon p4("Squirtle", "Water");

    teamA.addPokemon(p1);
    teamA.addPokemon(p2);
    teamB.addPokemon(p3);
    teamB.addPokemon(p4);

    ash.printTeams();

    std::cout << "\nPokemons in Kanto Team (forward):\n";
    teamA.printPokemonsForward();

    std::cout << "\nPokemons in Kanto Team (backward):\n";
    teamA.printPokemonsBackward();

    std::cout << "\nRemoving Charizard from Kanto Team...\n";
    teamA.removePokemon("Charizard");

    std::cout << "\nPokemons in Kanto Team after removal:\n";
    teamA.printPokemonsForward();

    return 0;
}

/* wynik działania:
Trainer: Ash Ketchum teams:
- Kanto Team
- Johto Team

Pokemons in Kanto Team (forward):
Pokemon: Pikachu (Type: Electric)
Pokemon: Charizard (Type: Fire)

Pokemons in Kanto Team (backward):
Pokemon: Charizard (Type: Fire)
Pokemon: Pikachu (Type: Electric)

Removing Charizard from Kanto Team...

Pokemons in Kanto Team after removal:
Pokemon: Pikachu (Type: Electric)
*/