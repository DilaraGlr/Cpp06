#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>  // Pour strtol, strtof, strtod
#include "Data.hpp"

class Serialization 
{
    private:
        Serialization(); // Empêche l'instanciation
        Serialization(const Serialization &);
        Serialization &operator=(const Serialization &);

    public:
        static uintptr_t serialize(Data* ptr);  
        static Data* deserialize(uintptr_t raw);
};

#endif
