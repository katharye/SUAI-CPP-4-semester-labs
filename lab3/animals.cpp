#include "animals.h"

void Animals::print_info() const {
    std::cout << "============ANIMALS============";
    std::cout << "\nbreed:        " << breed;
    std::cout << "\nname:         " << name;
    std::cout << "\ncolor:        " << color;
    std::cout << "\nowner`s name: " << owner_name;
    std::cout << "\nsize:         " << size;
    std::cout << "\n===============================\n";
}
void Animals::save_to_file(std::ofstream& out) const {
    if (is_initialized) {
        out << "ANIMALS\n" << breed << "\n" << name << "\n" << color << "\n" << owner_name << "\n" << size;
    }
}

Animals::Animals(std::ifstream& in) : Animals() {
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

Animals::Animals() {
    breed = "n/a";
    name = "n/a";
    color = "n/a";
    owner_name = "n/a";
    size = 1.0;
}
Animals::Animals(std::string breed, std::string name, std::string color, std::string owner_name, float size) {
    this->breed = breed;
    this->name = name;
    this->color = color;
    this->owner_name = owner_name;
    this->size = size;
    is_initialized = true;
}
Animals::Animals(const Animals& other) {
    if (other.is_initialized) {
        breed = other.breed;
        name = other.name;
        color = other.color;
        owner_name = other.owner_name;
        size = other.size;
        is_initialized = true;
    }
}
Animals::~Animals() {};
