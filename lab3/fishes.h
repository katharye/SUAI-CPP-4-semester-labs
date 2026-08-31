#ifndef FISHES_H
#define FISHES_H

#include "animals.h"


class Fishes: public Animals
{
public:
    void print_info() const override;
    void save_to_file(std::ofstream& out) const  override;
    
    Fishes();
    Fishes(std::ifstream& in);
    Fishes(std::string breed, std::string name, std::string color, std::string owner_name, float size);
    Fishes(const Fishes& other);
    ~Fishes() override;
};

#endif