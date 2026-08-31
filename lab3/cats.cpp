#include "cats.h"

void Cats::print_info() const {
    std::cout << "==============CATS==============";
    std::cout << "\nbreed:        " << breed;
    std::cout << "\nname:         " << name;
    std::cout << "\ncolor:        " << color;
    std::cout << "\nowner`s name: " << owner_name;
    std::cout << "\nsize:         " << size << "sm";
    std::cout << "\n================================\n";
}
void Cats::save_to_file(std::ofstream& out) const {
    if (is_initialized) {
        out << "CATS\n" << breed << "\n" << name << "\n" << color << "\n" << owner_name << "\n" << size;
    }
}

Cats::Cats() : Animals() {}

Cats::Cats(std::ifstream& in) : Cats() {
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
Cats::Cats(std::string breed, std::string name, std::string color, std::string owner_name, float size)
    : Animals(breed, name, color, owner_name, size) {}
Cats::Cats(const Cats& other) : Animals(other) {}
Cats::~Cats() {}
