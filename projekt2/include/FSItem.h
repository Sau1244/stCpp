#ifndef FSITEM_H
#define FSITEM_H

/* abstarakcyjna klasa bazowa */

#include <iostream>
#include <string>
#include <memory>

#include <fstream>
#include <filesystem>

class FSItem{
public:
    // destruktor wirtualny
    virtual ~FSItem() {};

    // abstrakcyjna siatka metody wyświetlającej
    virtual void print(std::ostream& os, int indent, const std::string& relativePath) const = 0;

    // abstrakcyjna siatka metody zwracającej nazwę
    virtual std::string getName() const = 0;

    // abstrakcyjna siatka kopiująca element
    virtual std::unique_ptr<FSItem> copy() const = 0;

    /* opcjonalne */

    // abstrakcyjna siatka tworząca realny element
    virtual void create(const std::string& path) const = 0;
};


#endif