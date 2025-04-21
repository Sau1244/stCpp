#include "Directory.h"

Directory::Directory(const std::string& name) : name(name) {}

Directory::~Directory() { std::cout << "Directory deleted " << getName() << "\n"; }

Directory::Directory(const Directory& other){
    for(const auto& item : other.items)
        items.push_back(item->copy());
}

Directory& Directory::operator=(const Directory& other){
    if(this != &other){
        items.clear();
        for(const auto& item : other.items)
            items.push_back(item->copy());
    }
    return *this;
}

Directory::Directory(Directory&& other) noexcept{
    items = std::move(other.items);
}

Directory& Directory::operator=(Directory&& other) noexcept{
    if(this != &other){
        items.clear();
        items = std::move(other.items);
    }
    return *this;
}

void Directory::addItem(std::unique_ptr<FSItem> item){
    items.push_back(std::move(item));
}

std::string Directory::getName() const{ return name; }

void Directory::print(std::ostream& os, int indent, const std::string& relativePath) const{
    // tworzenie ścieżki do katalogu
    std::string path;
    if(relativePath == getName()) path = getName();
    else path = relativePath + '/' + getName();

    // wyświetlanie nazwy oraz ścieżki do katalogu
    os << std::string(indent, ' ') << "Dir: " << getName() << " [path: " << path << "]\n";

    // wyświetlanie zawartości katalogu
    for(const auto& item : items)
        item->print(os,indent + 2,path);
}

std::unique_ptr<FSItem> Directory::copy() const{
    return std::make_unique<Directory>(*this);
}