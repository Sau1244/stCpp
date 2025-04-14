#include "Lion.h"

Lion::Lion(const std::string& name) : Animal(name) {}

void Lion::makeSound() const{
    std::cout << "Lion " << getName() << " roars: ROOAAAR!\n";
}

std::unique_ptr<Animal> Lion::clone() const{
    return std::make_unique<Lion>(*this);
}