// UTILIZANDO ARRAY
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

