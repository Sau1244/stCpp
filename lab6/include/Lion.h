#ifndef LION_H
#define LION_H

#include "Animal.h"

class Lion : public Animal{
public:
    Lion(const std::string& name);

    void makeSound() const override;

    std::unique_ptr<Animal> clone() const override;
};

#endif