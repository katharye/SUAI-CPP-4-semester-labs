#ifndef CATS_H
#define CATS_H

#include "animals.h"

class Cats: public Animals
{
public:
    void print_info() const override;
    void save_to_file(std::ofstream& out) const  override;

    Cats();
    Cats(std::ifstream& in);
    Cats(std::string breed, std::string name, std::string color, std::string owner_name, float size);
    Cats(const Cats& other);    
    ~Cats() override;
};

#endif