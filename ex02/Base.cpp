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
}

void identify(Base* p) 
{
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
}

void identify(Base& p) 
{
    try 
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;  // Ignore la variable si non utilisée
        std::cout << "Type : A" << std::endl;
    }
    catch (std::bad_cast&) 
    {
        try 
        {
            B& b = dynamic_cast<B&>(p);
            (void)b;  // Ignore la variable si non utilisée
            std::cout << "Type : B" << std::endl;
        }
        catch (std::bad_cast&) 
        {
            try 
            {
                C& c = dynamic_cast<C&>(p);
                (void)c;  // Ignore la variable si non utilisée
                std::cout << "Type : C" << std::endl;
            }
            catch (std::bad_cast&) 
            {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}
