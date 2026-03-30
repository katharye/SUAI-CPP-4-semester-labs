#ifndef HUMANS_H
#define HUMANS_H

#include "mammals.h"

class Humans: public Mammals
{
private:
    std::string FIO;

    int date_of_birth[3];
    std::string nationality;
public:
    void print_info() const override;
    void save_to_file(std::ofstream& out) const  override;

    Humans();
    Humans(std::ifstream& in);
    Humans(std::string fFIO, int date_of_birth[3], std::string nationality);
    Humans(const Humans& other);
    ~Humans() override;
};

#endif