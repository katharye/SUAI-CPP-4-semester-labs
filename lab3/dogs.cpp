#include "dogs.h"

void Dogs::print_info() const {
    std::cout << "==============DOGS==============";
    std::cout << "\nbreed:        " << breed;
    std::cout << "\nname:         " << name;
    std::cout << "\ncolor:        " << color;
    std::cout << "\nowner`s name: " << owner_name;
    std::cout << "\nsize:         " << size << "dm";
    std::cout << "\n================================\n";
}
void Dogs::save_to_file(std::ofstream& out) const {
    if (is_initialized) {
        out << "DOGS\n" << breed << "\n" << name << "\n" << color << "\n" << owner_name << "\n" << size;
    }
}

Dogs::Dogs() : Animals() {}
Dogs::Dogs(std::ifstream& in) : Dogs() {
    std::string str;
    std::getline(in, str);
    breed = str;
    std::getline(in, str);
    name = str;
    std::getline(in, str);
    color = str;
    std::getline(in, str);
    owner_name = str;

    in >> size;

    is_initialized = true;
}
Dogs::Dogs(std::string breed, std::string name, std::string color, std::string owner_name, float size)
    : Animals(breed, name, color, owner_name, size) {}
Dogs::Dogs(const Dogs& other) : Animals(other) {}
Dogs::~Dogs() {}
