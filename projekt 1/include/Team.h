#ifndef TEAM_H
#define TEAM_H

#include "Pokemon.h"

// Klasa reprezentująca drużynę Pokemon
class Team{
private:
    std::string m_name; // Nazwa drużyny
    PokemonNode* m_head; // Wskaźnik na pierwszego Pokemona
    PokemonNode* m_tail; // Wskaźnik na ostatniego Pokemona
public:
    //Konstruktor inicjujący drużynę (nazwa drużyny)
    Team(const std::string& name);
    // Destruktor zwalniający pamięć wszystkich elementów listy
    ~Team();

    // Metoda dodająca Pokemona do drużyny
    void addPokemon(Pokemon& pokemon);
    //Metoda usuwająca Pokemona z drużyny
    void removePokemon(const std::string& name);

    // Operator umożliwiający dostęp do Pokemona przez indeks
    Pokemon& operator[](int index);

    // Metoda wyświetlająca Pokemony od pierwszego elementu
    void printPokemonsForward() const;
    // Metoda wyświetlająca Pokemony od ostatniego elementu
    void printPokemonsBackward() const;

    // Metoda zwracająca nazwę drużyny
    std::string getName() const;
};

// Struktura reprezentująca węzeł listy dwukierunkowej drużyn
struct TeamNode{
    Team team; // Drużyna
    TeamNode *next; // Wskaźnik na kolejną Drużynę
    TeamNode *prev; // Wskaźnik na poprzednią Drużynę

    //Konstruktor inicjujący węzeł
    TeamNode(const Team& team);
};

#endif