#include "ScalarConverter.hpp"
#include <cfloat>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cerrno>
#include <climits>

bool ScalarConverter::isSpecialCase(const std::string &literal)
{
    return literal == "nan" || literal == "nanf" || literal == "-inf" || literal == "+inf" || literal == "inf" ||
           literal == "-inff" || literal == "+inff" || literal == "inff";
}

bool ScalarConverter::isChar(const std::string &literal)
{
    return literal.length() == 1 && std::isprint(literal[0]);
}

bool ScalarConverter::isInt(const std::string &literal)
{
    char *endptr;
    std::strtol(literal.c_str(), &endptr, 10);
    return *endptr == '\0' && !literal.empty();
}

bool ScalarConverter::isFloat(const std::string &literal)
{
    char *endptr;
    std::strtof(literal.c_str(), &endptr);
    return *endptr == 'f' && *(endptr + 1) == '\0' && !literal.empty();
}

bool ScalarConverter::isDouble(const std::string &literal)
{
    char *endptr;
    std::strtod(literal.c_str(), &endptr);
    return *endptr == '\0' && !literal.empty();
}

void ScalarConverter::convert(const std::string &literal)
{
    char c;
    int i;
    float f;
    double d;

    std::cout << std::fixed << std::setprecision(6);  // Définit la précision pour float et double à 6 chiffres significatifs

    // Gestion des cas spéciaux (nan, inf, etc.)
    if (isSpecialCase(literal))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << ((literal[literal.length() - 1] == 'f') ? "" : "f") << std::endl;
        std::cout << "double: " << literal << ((literal[literal.length() - 1] == 'f') ? "f" : "") << std::endl;
        return;
    }

    errno = 0;
    if (isChar(literal))
    {
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    else if (isInt(literal))
    {
        char *endptr;
        long tmp = std::strtol(literal.c_str(), &endptr, 10);
        // Vérification pour éviter les dépassements de limites sur les int
        if (*endptr != '\0' || errno == ERANGE || tmp > INT_MAX || tmp < INT_MIN)
        {
            i = INT_MIN;  // On définit i comme une valeur invalide pour éviter les conversions incorrectes
        }
        else
        {
            i = static_cast<int>(tmp);
        }
        c = static_cast<char>(i);
        f = static_cast<float>(tmp);  // Toujours essayer de convertir en float
        d = static_cast<double>(tmp); // Toujours essayer de convertir en double
    }
    else if (isFloat(literal))
    {
        char *endptr;
        d = std::strtod(literal.c_str(), &endptr);  // Convertir en double d'abord
        if (*endptr != 'f' || errno == ERANGE || std::fabs(d) == HUGE_VAL)
        {
            std::cout << "float: impossible" << std::endl;
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        i = static_cast<int>(d);  // Convertir en int
        c = static_cast<char>(i); // Convertir en char
        f = static_cast<float>(d); // Utiliser float seulement pour l'affichage
    }
    else if (isDouble(literal))
    {
        char *endptr;
        d = std::strtod(literal.c_str(), &endptr);  // Convertir en double d'abord
        if (*endptr != '\0' || errno == ERANGE || std::fabs(d) == HUGE_VAL)
        {
            std::cout << "double: impossible" << std::endl;
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            return;
        }
        i = static_cast<int>(d);  // Convertir en int
        c = static_cast<char>(i); // Convertir en char
        f = static_cast<float>(d); // Utiliser float seulement pour l'affichage
    }
    else
    {
        std::cout << "Error: Unknown type" << std::endl;
        return;
    }

    // Affichage du résultat pour char
    std::cout << "char: ";
    if (i < 32 || i > 126)  // Si le caractère n'est pas imprimable
        std::cout << "impossible" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;

    // Affichage du résultat pour int
    std::cout << "int: ";
    if (i == INT_MIN)  // Vérification explicite de la valeur invalide
        std::cout << "impossible" << std::endl;
    else
        std::cout << i << std::endl;

    // Affichage du résultat pour float
    std::cout << "float: ";
    if (errno == ERANGE || std::fabs(f) == HUGE_VALF)
        std::cout << "impossible" << std::endl;
    else
        std::cout << std::scientific << f << "f" << std::endl;

    // Affichage du résultat pour double
    std::cout << "double: ";
    if (errno == ERANGE || std::fabs(d) == HUGE_VAL)
        std::cout << "impossible" << std::endl;
    else
        std::cout << std::scientific << d << std::endl;
}
