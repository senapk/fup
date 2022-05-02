#include <iostream>
#include <vector> //container, collection

void print(std::vector<int> vet) {
    int size = vet.size();
    std::cout << "[";
    for (int i = 0; i < size; i += 1)
        std::cout << (i == 0 ? "" : ", ") << vet[i];
    std::cout << "]\n";
}

std::vector<int> pegar_impares(std::vector<int> vet) {
    std::vector<int> impares;
    int size = vet.size();
    for (int i = 0; i < size; i++)
        if (vet[i] % 2 == 1)
            impares.push_back(vet[i]);
    return impares;
}

int main() {
    int size { };
    std::cin >> size;

    std::vector<int> vet(size);
    for (int i = 0; i < size; i++)
        std::cin >> vet[i];

    auto impares = pegar_impares(vet);

    print(impares);
}