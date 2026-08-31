#ifndef DOGS_H
#define DOGS_H

#include "animals.h"

class Dogs: public Animals
{
public:
    void print_info() const override;
    void save_to_file(std::ofstream& out) const  override;

    Dogs();  
    Dogs(std::ifstream& in);    
    Dogs(std::string breed, std::string name, std::string color, std::string owner_name, float size);
    Dogs(const Dogs& other);
    ~Dogs() override;    
};

#endif