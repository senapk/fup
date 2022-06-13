#include <iostream>

void imprima(int vet[], int size);

void leia(int vet[], int size);

void preencha_impares(int vet[], int size, int impares[], int &impares_size);

int main() {
    int size { };
    std::cin >> size;

    int vet[size] = {}; //cria um ARRAY de size elementos INICIALIZADOS com 0
    
    leia(vet, size); //le da entrada

    int impares[size] = {}; //cria impares com espaco suficienta para caber
    int impares_size = 0;
    preencha_impares(vet, size, impares, impares_size); //preenche impares
    imprima(impares, impares_size);
}

//ACESSANDO
//precisa passar o size
void imprima(int vet[], int size) {
    std::cout << "[ "; 
    for (int i = 0; i < size; i++) //array suporta apenas esse tipo de loop
        std::cout << vet[i] << " ";
    std::cout << "]\n";
}

//ALTERANDO
//    precisa passar o size, 
//não precisa de referencia
void leia(int vet[], int size) {
    for (int i = 0; i < size; i++)
        std::cin >> vet[i];
}

//RETORNANDO
//não é possível retornar NOVOS arrays
//apenas receber e preencher
void preencha_impares(int vet[], int size, int impares[], int &impares_size) {
    impares_size = 0;
    for (int i = 0; i < size; i++)
        if(vet[i] % 2 == 1)
            impares[impares_size++] = vet[i];
}
