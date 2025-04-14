#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <memory>

class Animal{
private:
    std::string name;
public:
    Animal(const std::string& name);
    virtual ~Animal();

    std::string getName() const;

    virtual void makeSound() const = 0;

    virtual std::unique_ptr<Animal> clone() const = 0;
};

#endif