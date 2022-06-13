// UTILIZANDO ARRAY
#include <iostream>
int main() {
    int size { };
    std::cin >> size;

    int vet[size] = {}; //cria um ARRAY de size elementos INICIALIZADOS com 0
    
    for (int i = 0; i < size; i++)
        std::cin >> vet[i];

    std::cout << "[ "; 
    for (int i = 0; i < size; i++) //array suporta apenas esse tipo de loop
        std::cout << vet[i] << " ";
    std::cout << "]\n";
}
