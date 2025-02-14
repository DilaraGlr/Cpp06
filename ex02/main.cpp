#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() 
{
    Base* basePtr = NULL;  // Crée un objet aléatoire
    std::cout << "Using pointer:" << std::endl;
    identify(basePtr);  // Identifie via pointeur

    std::cout << "Using reference:" << std::endl;
    identify(*basePtr);  // Identifie via référence

    delete basePtr;  // N'oublie pas de libérer la mémoire
    return 0;
}
