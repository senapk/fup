// UTILIZANDO VECTOR
#include <iostream>
#include <vector>
int main() {
    int size { };
    std::cin >> size;

    std::vector<int> vet(size); //cria um VECTOR de size elementos INICIALIZADOS com 0
    
    for (int i = 0; i < size; i++)
        std::cin >> vet[i];

    std::cout << "[ "; 
    for (int x : vet) //vector suporta vários tipos de loop
        std::cout << x << " ";
    std::cout << "]\n";
}
