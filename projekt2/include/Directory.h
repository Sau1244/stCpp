#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "FSItem.h"
#include <vector>

class Directory : public FSItem{
private:
    std::string name; // nazwa katalogu
    std::vector<std::unique_ptr<FSItem>> items; // kolekcja elementów FSItem
public:
    // konstruktor inicjujący przyjmujący argument (name)
    Directory(const std::string& name);

    /* rule of five */
    // destruktor
    ~Directory();
    // konstruktor kopiujący
    Directory(const Directory& other);
    // operator kopiujący
    Directory& operator=(const Directory& other);
    // konstruktor przenoszący
    Directory(Directory&& other) noexcept;
    // operator przenoszący
    Directory& operator=(Directory&& other) noexcept;

    // metoda dodająca element do kolekcji
    void addItem(std::unique_ptr<FSItem> item);

    // metoda zwracająca nazwę katalogu
    std::string getName() const override;

    // metoda wyświetlająca nazwę oraz zawartość katalogu
    void print(std::ostream& os, int indent, const std::string& relativePath) const override;

    // metoda kopiująca katalog
    std::unique_ptr<FSItem> copy() const override;
};

#endif