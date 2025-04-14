#include "Zoo.h"

Zoo::Zoo(){}

Zoo::~Zoo(){
    std::cout << "Zoo destroyed.\n";
}

Zoo::Zoo(const Zoo &other) {
    for(const auto& animal : other.animals)
        animals.push_back(animal->clone());
}

Zoo& Zoo::operator=(const Zoo &other) {
    if(this != &other){
        for(const auto& animal : other.animals)
            animals.push_back(animal->clone());
    }

    return *this;
}

Zoo::Zoo(Zoo&& other){
    animals = std::move(other.animals);
}

Zoo& Zoo::operator=(Zoo&& other){
    if(this != &other){
        animals = std::move(other.animals);
    }
    return *this;
}

void Zoo::addAnimal(std::unique_ptr<Animal> newAnimal){
    animals.push_back(std::move(newAnimal));
}

void Zoo::makeAnimalSound(int index) {
    if(!animals.empty()) animals[index]->makeSound();
    else std::cout << "Zoo is empty, no animals to make sounds!\n";
}