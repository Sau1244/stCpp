#include "Animal.h"

Animal::Animal(const std::string& name) : name(name){}

Animal::~Animal() {};

std::string Animal::getName() const{ return name; }
