#ifndef MONKEY_H
#define MONKEY_H

#include "Animal.h"

class Monkey : public Animal{
public:
    Monkey(const std::string& name);

    void makeSound() const override;

    std::unique_ptr<Animal> clone() const override;
};

#endif