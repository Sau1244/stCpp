#ifndef FILE_H
#define FILE_H

#include "FSItem.h"

class File : public FSItem{
private:
    std::string name; // nazwa pliku
public:
    // konstruktor inicjujący przyjmujący argument (name)
    File(const std::string& name);
    // destruktor
    ~File();

    // metoda zwracająca nazwę pliku
    std::string getName() const override;

    // metoda wyświetlająca nazwę oraz ścieżkę pliku
    void print(std::ostream& os, int indent, const std::string& relativePath) const override;

    // metoda kopiująca plik
    std::unique_ptr<FSItem> copy() const override;
};

#endif