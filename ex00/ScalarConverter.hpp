#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>  // Pour strtol, strtof, strtod

class ScalarConverter 
{
    private:
        ScalarConverter(); // Empêche l'instanciation
        ScalarConverter(const ScalarConverter &);
        ScalarConverter &operator=(const ScalarConverter &);

    public:
        static void convert(const std::string &literal);
};

#endif