#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"
#include <vector>

class Zoo{
private:
    std::vector<std::unique_ptr<Animal>> animals;
public:
    Zoo();
    ~Zoo();

    Zoo(const Zoo& other);
    Zoo& operator=(const Zoo& other);

    Zoo(Zoo&& other);
    Zoo& operator=(Zoo&& other);

    void addAnimal(std::unique_ptr<Animal> newAnimal);

    void makeAnimalSound(int index);
};

#endif