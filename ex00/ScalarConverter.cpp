#include "ScalarConverter.hpp"

static bool isChar(const std::string &s)
{
	if (s.length() != 1)
	{
		return (false);
	}
	return (std::isprint(s[0]));
	return (1);
}

static bool isInt(const std::string &s) 
{
    for (size_t i = (s[0] == '-' ? 1 : 0); i < s.length(); i++)
        if (!isdigit(s[i])) return false;
    return true;
}

static bool isFloat(const std::string &s) 
{
    return (s.find('.') != std::string::npos && s.back() == 'f');
}

static bool isDouble(const std::string &s) 
{
    return (s.find('.') != std::string::npos && s.back() != 'f');
}

static bool isSpecialCase(const std::string &s) 
{
    return (s == "nan" || s == "nanf" || s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff");
}

void ScalarConverter::convert(const std::string &literal) 
{
    char c;
    int i;
    float f;
    double d;

    std::cout << std::fixed << std::setprecision(1); // Fixe l'affichage à une décimale

    // Cas spéciaux (nan, inf, etc.)
    if (isSpecialCase(literal)) 
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << (literal.back() == 'f' ? "" : "f") << std::endl;
        std::cout << "double: " << literal << (literal.back() == 'f' ? "f" : "") << std::endl;
        return;
    }

    // Vérification des types
    if (isChar(literal)) 
    {
        c = literal[1];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    else if (isInt(literal)) 
    {
        long tmp = std::strtol(literal.c_str(), NULL, 10);
        if (tmp > std::numeric_limits<int>::max() || tmp < std::numeric_limits<int>::min()) 
        {
            std::cout << "int: impossible" << std::endl;
            return;
        }
        i = static_cast<int>(tmp);
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    }
    else if (isFloat(literal)) 
    {
        f = std::strtof(literal.c_str(), NULL);
        i = static_cast<int>(f);
        c = static_cast<char>(i);
        d = static_cast<double>(f);
    }
    else if (isDouble(literal)) 
    {
        d = std::strtod(literal.c_str(), NULL);
        i = static_cast<int>(d);
        c = static_cast<char>(i);
        f = static_cast<float>(d);
    }
    else 
    {
        std::cout << "Error: Unknown type" << std::endl;
        return;
    }

    // Affichage des conversions
    std::cout << "char: ";
    if (isprint(i))
        std::cout << "'" << c << "'" << std::endl;
    else if (i >= 0 && i <= 127)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "impossible" << std::endl;

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}
