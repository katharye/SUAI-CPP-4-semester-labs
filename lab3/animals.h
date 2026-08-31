#ifndef ANIMALS_H
#define ANIMALS_H

#include "mammals.h"

class Animals: public Mammals
{
protected:
    std::string breed; 
    std::string name;
    std::string color;
    std::string owner_name; 
    float size;  
public:
    void print_info() const override;
    void save_to_file(std::ofstream& out) const  override;

    Animals();
    Animals(std::ifstream& in);
    Animals(std::string breed, std::string name, std::string color, std::string owner_name, float size);
    Animals(const Animals& other);
    ~Animals() override;
};

#endif