#include "Monkey.h"

Monkey::Monkey(const std::string& name) : Animal(name){}

void Monkey::makeSound() const {
    std::cout << "Monkey " << getName() << " says: Ooh-ooh-aah-aah!\n";
}

std::unique_ptr<Animal> Monkey::clone() const {
    return std::make_unique<Monkey>(*this);
}