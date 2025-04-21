#include "FSItem.h"
#include "File.h"
#include "Directory.h"

/* metody pomocnicze */
std::unique_ptr<Directory> makeDir(const std::string& name);
std::unique_ptr<File> makeFile(const std::string& name);

int main(){

    // tworzenie głównego katalogu
    std::unique_ptr<Directory> project = makeDir("project");
    // dodawanie pliku do głównego katalogu
    project->addItem(makeFile("README.md"));

    // tworzenie podkatalogu src i dodawanie do niego elementów
    std::unique_ptr<Directory> src = makeDir("src");
    src->addItem(makeFile("main.cpp"));
    src->addItem(makeFile("utils.cpp"));
    // przypisanie podkatalogu src do głównego katalogu
    project->addItem(std::move(src));

    // tworzenie podkatalogu assets i images
    std::unique_ptr<Directory> assets = makeDir("assets");
    std::unique_ptr<Directory> images = makeDir("images");
    // dodawanie elementów do katalogu images
    images->addItem(makeFile("logo.png"));
    images->addItem(makeFile("banner.jpg"));

    // dodanie images jako podkatalog assets
    assets->addItem(std::move(images));
    // dodanie assets jako podkatalog głównego katalogu
    project->addItem(std::move(assets));

    project->print(std::cout, 0, project->getName());

    return 0;
}

std::unique_ptr<Directory> makeDir(const std::string& name){
    return std::make_unique<Directory> (name);
}

std::unique_ptr<File> makeFile(const std::string& name){
    return std::make_unique<File> (name);
}