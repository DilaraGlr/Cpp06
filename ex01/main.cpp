#include <iostream>
#include "Serialization.hpp"

int main() 
{
    // Créer un objet Data
    Data data = {"Hello", 42, "World"};

    // Afficher les valeurs avant sérialisation
    std::cout << "Data number: " << data.n << std::endl;
    std::cout << "Original address: " << &data << std::endl;

    // Sérialiser l'objet Data
    uintptr_t serialized = Serialization::serialize(&data);
    std::cout << "Serialized: " << serialized << std::endl;

    // Désérialiser l'objet Data
    Data* deserialized = Serialization::deserialize(serialized);
    std::cout << "Deserialized number: " << deserialized->n << std::endl;
    std::cout << "Deserialized address: " << deserialized << std::endl;

    // Comparer les adresses
    if (&data == deserialized) 
    {
        std::cout << "Addresses are the same!" << std::endl;
    } 
    else 
    {
        std::cout << "Addresses are different!" << std::endl;
    }

    return 0;
}
