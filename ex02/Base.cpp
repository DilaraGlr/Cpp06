#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) 
{
    srand(time(0));  // Initialisation du générateur aléatoire
    int random = rand() % 3;  // Choisir un nombre aléatoire entre 0 et 2

    if (random == 0) 
    {
        std::cout << "A created" << std::endl;
        return new A;  // Crée une instance de A
    }
    else if (random == 1)
    {
        std::cout << "B created" << std::endl;
        return new B;  // Crée une instance de B
    }
    else 
    {
        std::cout << "C created" << std::endl;
        return new C;  // Crée une instance de C
    }
    return NULL;
}

void identify(Base* p) 
{
    if(!p) 
    {
        std::cout << "Unknown type" << std::endl;
        return;
    }
    if (dynamic_cast<A*>(p)) 
    {
        std::cout << "Type : A" << std::endl;
    }
    else if (dynamic_cast<B*>(p)) 
    {
        std::cout << "Type : B" << std::endl;
    }
    else if (dynamic_cast<C*>(p)) 
    {
        std::cout << "Type : C" << std::endl;
    }
    else 
    {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) 
{
   try
	{
		if (dynamic_cast<A *>(&p))
			std::cout << "Type : A" << std::endl;
		else if (dynamic_cast<B *>(&p))
			std::cout << "Type : B" << std::endl;
		else if (dynamic_cast<C *>(&p))
			std::cout << "Type : C" << std::endl;
		else
			throw std::exception();
		;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Type : undefined" << '\n';
	}
    }

