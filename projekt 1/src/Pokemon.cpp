#include "Pokemon.h"

Pokemon::Pokemon(const std::string &name, const std::string &type) : m_name(name), m_type(type) {}

void Pokemon::printInfo() const {
    std::cout << "Pokemon: " << m_name << " (Type: " << m_type << ")\n";
}

PokemonNode::PokemonNode(const Pokemon& pokemon) : pokemon(pokemon), next(nullptr), prev(nullptr) {}

std::string Pokemon::getName() const {
    return m_name;
}