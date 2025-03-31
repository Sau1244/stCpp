#include "Team.h"

Team::Team(const std::string &name) : m_name(name), m_head(nullptr), m_tail(nullptr){}

Team::~Team(){
    PokemonNode *current = m_head;
    while(current){
        current = m_head->next;
        delete m_head;
        m_head = current;
    }
}

TeamNode::TeamNode(const Team &team) : team(team), next(nullptr), prev(nullptr){}

void Team::addPokemon(Pokemon &pokemon) {
    PokemonNode *newNode = new PokemonNode(pokemon);
    if(!m_head){
        m_head = m_tail = newNode;
    }else{
        m_tail->next = newNode;
        newNode->prev = m_tail;
        m_tail = newNode;
    }
}

void Team::removePokemon(const std::string& name) {
    PokemonNode* current = m_head;
    while(current && current->pokemon.getName() != name){
        current = current->next;
    }
    if(current) {
        if(current == m_head) m_head = current->next;
        if(current == m_tail) m_tail = current->prev;
        if(current->prev) current->prev->next = current->next;
        if(current->next) current->next->prev = current->prev;
        delete current;
    }else{
        std::cout << "Nie znaleziono takiego pokemona!\n";
    }
}

Pokemon& Team::operator[](int index){
    int i = 0;
    PokemonNode* current = m_head;
    while(i < index && current){
        current = current->next;
        i++;
    }
    return current->pokemon;
}

void Team::printPokemonsForward() const {
    PokemonNode* current = m_head;
    while(current){
        current->pokemon.printInfo();
        current = current->next;
    }
}

void Team::printPokemonsBackward() const {
    PokemonNode* current = m_tail;
    while(current){
        current->pokemon.printInfo();
        current = current->prev;
    }
}

std::string Team::getName() const {
    return m_name;
}