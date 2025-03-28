#ifndef TRAINER_H
#define TRAINER_H

#include "Team.h"

// Klasa reprezentująca Trenera Pokemon
class Trainer{
private:
    std::string m_name; // Imię trenera
    TeamNode *m_head; // Wskaźnik na pierwszą drużynę
    TeamNode *m_tail; // Wskaźnik na ostatnią drużynę
public:
    // Konstruktor inicjujący trenera (imię trenera)
    Trainer(const std::string& name);
    // Destruktor zwalniający pamięć wszystkich elementów listy
    ~Trainer();

    // Metoda przypisująca drużynę do trenera
    void addTeam(Team& team);
    // Metoda wyświetlająca przypisane drużyny do trenera
    void printTeams() const;
};

#endif