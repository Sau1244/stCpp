#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <iostream>

// klasa reprezentująca pojedyńcze Pokemony
class Pokemon{
private:
    std::string m_name; // Nazwa Pokemona
    std::string m_type; // Typ Pokemona
public:
    // Konstruktor inicjująca Pokemona (nazwa, typ)
    Pokemon(const std::string& name, const std::string& type);

    // Metoda wyświetlająca informacje o Pokemonie
    void printInfo() const;

    // Metoda zwracająca nazwę Pokemona
    std::string getName() const;
};

// Struktura reprezentująca węzeł listy dwukierunkowej Pokemonów
struct PokemonNode{
    Pokemon pokemon; // Dane Pokemona
    PokemonNode *next; // Wskaźnik na kolejnego Pokemona
    PokemonNode *prev; // Wskaźnik na poprzedniego Pokemona

    // Konstruktor inicjujący węzeł
    PokemonNode(const Pokemon& pokemon);
};

#endif