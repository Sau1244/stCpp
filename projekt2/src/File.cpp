#include "File.h"

File::File(const std::string& name) : name(name){}

File::~File(){ std::cout << "File deleted " << name << "\n"; }

std::string File::getName() const{ return name; }

void File::print(std::ostream& os, int indent, const std::string& relativePath) const{
    os << std::string(indent, ' ') << "File: " << name << " [path: " << relativePath << "]\n";
}

std::unique_ptr<FSItem> File::copy() const{
    return std::make_unique<File>(*this);
}

void File::create(const std::string& path) const{ std::ofstream file(path+'/'+name); }