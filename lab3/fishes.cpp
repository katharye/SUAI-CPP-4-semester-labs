#include "fishes.h"

void Fishes::print_info() const {
    std::cout << "==============FISHES==============";
    std::cout << "\nbreed:        " << breed;
    std::cout << "\nname:         " << name;
    std::cout << "\ncolor:        " << color;
    std::cout << "\nowner`s name: " << owner_name;
    std::cout << "\nsize:         " << size << "sm";
    std::cout << "\n================================\n";
}
void Fishes::save_to_file(std::ofstream& out) const {
    if (is_initialized) {
        out << "FISHES\n" << breed << "\n" << name << "\n" << color << "\n" << owner_name << "\n" << size;
    }
}

Fishes::Fishes() : Animals() {}
Fishes::Fishes(std::ifstream& in) : Fishes() {
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
Fishes::Fishes(std::string breed, std::string name, std::string color, std::string owner_name, float size)
    : Animals(breed, name, color, owner_name, size) {}
Fishes::Fishes(const Fishes& other) : Animals(other) {}
Fishes::~Fishes() {}