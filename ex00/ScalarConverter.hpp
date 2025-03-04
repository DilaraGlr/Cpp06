#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <iomanip>
#include <cerrno>
#include <cmath>  // Pour strtol, strtof, strtod

class ScalarConverter 
{
    private:
        ScalarConverter(); // Empêche l'instanciation
        ScalarConverter(const ScalarConverter &);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &);
        static bool isSpecialCase(const std::string &literal);
        static bool isChar(const std::string &literal);
        static bool isInt(const std::string &literal);
        static bool isFloat(const std::string &literal);
        static bool isDouble(const std::string &literal);

    public:
        static void convert(const std::string &literal);
};

#endif