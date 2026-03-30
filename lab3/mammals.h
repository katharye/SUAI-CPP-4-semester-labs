#ifndef MAMMALS_H
#define MAMMALS_H

#include <string>
#include <iostream>
#include <fstream>

class Mammals 
{
protected:
    bool is_initialized = false;
public:
    virtual void print_info() const = 0;
    virtual void save_to_file(std::ofstream& out) const = 0;

    Mammals();
    Mammals(std::ifstream& in);
    Mammals(const Mammals& other);
    virtual ~Mammals() = 0;
};

#endif