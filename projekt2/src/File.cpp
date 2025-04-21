#include "File.h"

File::File(const std::string& name) : name(name){}

File::~File(){ std::cout << "File deleted " << getName() << "\n"; }

std::string File::getName() const{ return name; }

void File::print(std::ostream& os, int indent, const std::string& relativePath) const{
    os << std::string(indent, ' ') << "File: " << getName() << " [path: " << relativePath << "]\n";
}

std::unique_ptr<FSItem> File::copy() const{
    return std::make_unique<File>(*this);
}

void File::create(const std::string& path) const{ std::ofstream file(path+'/'+getName()); }