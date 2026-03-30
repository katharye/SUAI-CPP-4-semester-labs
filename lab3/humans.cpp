#include "humans.h"

void Humans::print_info() const {
    std::cout << "=============HUMANS=============";
    std::cout << "\nFIO:           " << FIO;
    std::cout << "\ndate of birth: " << date_of_birth[0] << "/" << date_of_birth[1] << "/"
              << date_of_birth[2];
    std::cout << "\nnationality:    " << nationality;
    std::cout << "\n================================\n";
}
void Humans::save_to_file(std::ofstream& out) const {
    if (is_initialized) {
        out << "HUMANS\n"
            << FIO << "\n"
            << nationality << "\n"
            << date_of_birth[0] << " " << date_of_birth[1] << " " << date_of_birth[2];
    }
}
Humans::Humans() {
    FIO = "n/a";
    date_of_birth[0] = 1;
    date_of_birth[1] = 1;
    date_of_birth[2] = 1;
    nationality = "n/a";
}
Humans::Humans(std::ifstream& in) : Humans() {
    std::string str;
    std::getline(in, str);
    FIO = str;
    std::getline(in, str);
    nationality = str;

    in >> date_of_birth[0];
    in >> date_of_birth[1];
    in >> date_of_birth[2];

    is_initialized = true;
}
Humans::Humans(std::string FIO, int date_of_birth[3], std::string nationality) {
    this->FIO = FIO;
    this->date_of_birth[0] = date_of_birth[0];
    this->date_of_birth[1] = date_of_birth[1];
    this->date_of_birth[2] = date_of_birth[2];
    this->nationality = nationality;

    is_initialized = true;
}
Humans::Humans(const Humans& other) {
    this->FIO = other.FIO;
    this->date_of_birth[0] = other.date_of_birth[0];
    this->date_of_birth[1] = other.date_of_birth[1];
    this->date_of_birth[2] = other.date_of_birth[2];
    this->nationality = other.nationality;
    is_initialized = true;
}
Humans::~Humans() {}