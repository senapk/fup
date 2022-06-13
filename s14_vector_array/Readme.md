# Arrays e Vectors

Vamos fazer um paralelo entre 
- array - estrutura primitiva do C e C++ para guardar uma coleção de elementos do mesmo tipo.
- vector - classe do c++ para guardar uma coleção de elementos.

## Lendo uma lista de inteiros e imprimindo.

```txt
>>>>>>>>
5
3 4 2 5 6
========
[ 3 4 2 5 6 ]
<<<<<<<<
```

### VECTOR

[](save)[](_vec1.cpp)
```cpp
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
```
[](save)

### ARRAY

[](save)[](_vec2.cpp)
```cpp
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
```
[](save)



___
## Passando para função


1. Leia uma lista de números em um vetor.
2. Crie um nova lista apenas com os impares.
3. Imprima a nova lista.
4. Para cada ação, crie uma função separada.

```txt
>>>>>>>>
7
3 4 2 5 6 1 2
========
[ 3 5 1 ]
<<<<<<<<
```

### VECTOR

[](save)[](_impares1.cpp)
```cpp
#include <iostream>
#include <vector>
using namespace std;


void imprima(vector<int> vet);

void leia(vector<int>& vet);

vector<int> get_impares(vector<int> vet);

int main() {
    int size { };
    std::cin >> size;

    vector<int> vet(size); //cria um VECTOR de size elementos INICIALIZADOS com 0
    
    leia(vet); //le da entrada
    vector<int> impares = get_impares(vet);
    imprima(impares);
}

//ACESSANDO
//não precisa passar o size
void imprima(vector<int> vet) {
    int size = vet.size();
    std::cout << "[ "; 
    for (int x : vet) //array suporta apenas esse tipo de loop
        std::cout << x << " ";
    std::cout << "]\n";
}

//ALTERANDO
//não precisa passar o size
//    precisa de referencia
void leia(vector<int>& vet) {
    int size = vet.size();
    for (int i = 0; i < size; i++)
        std::cin >> vet[i];
}

//RETORNANDO
//é possível retornar NOVOS vectors
vector<int> get_impares(vector<int> vet) {
    vector<int> impares; //criando vazio
    for (int x : vet)
        if(x % 2 == 1)            // utilizando o método da classe vector
            impares.push_back(x); //criando espaço e adicionando no final
    return impares;
}

```
[](save)

### ARRAY

[](save)[](_impares2.cpp)
```cpp
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
```
[](save)



