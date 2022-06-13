#include <iostream>
#include <vector>
using namespace std;

bool in(vector<int> vet, int value) {
    for (int elem : vet)
        if (elem == value)
            return true;
    return false;
}

int index_of(vector<int> vet, int value) {
    for (int i = 0; i < (int) vet.size(); i++)
        if (vet[i] == value)
            return i;
    return -1;
}


//[5,4,1,2]
//posicao do menor elemento
int menor_par(vector<int> vet) {
    int size = vet.size();
    int pos = -1;
    for (int i = 0; i < size; i++) {
        if (vet[i] % 2 != 0)
            continue;
        if (pos == -1 || vet[i] < vet[pos])
            pos = i; 
    }
    return pos;
}

int count(vector<int> vet, int value) {
    int cont { 0 };
    for (int elem : vet)
        if (elem == value)
            cont += 1;
    return cont;
}

float media(vector<int> vet) {
    float acc = 0;
    for (int elem : vet)
        acc += elem;
    return acc / vet.size();
}

// [min, max[
// int rand(int min, int max) {
//     return rand() % (max - min) + min;
// }

float media(vector<int> vet, int inicio, int fim) {
    float acc = 0;
    for (int i = inicio; i < fim; i++)
        acc += vet[i];
    return acc / (fim - inicio);
}

string compare(int a, int b, string igual, string maior, string menor) {
    if (a == b)
        return igual;
    return a > b ? maior : menor;
}

string qual_metade_maior(vector<int> vet) {
    int size = vet.size();
    int primeira = media(vet, 0, size / 2);
    int meio = size / 2;
    if (size % 2 == 1)
        meio += 1;
    int segunda = media(vet, meio, size);
    return compare(primeira, segunda, "empate", "segunda", "primeira");
}

string mais_pares_ou_impares(vector<int> vet) {
    int npares { 0 }, nimpares { 0 };
    for (int elem : vet) {
        if (elem % 2 == 0)
            npares += 1;
        else
            nimpares += 1;
    }
    return compare(npares, nimpares, "empate", "impares", "pares");
}






int main() {
    int size { }, proc { };
    cin >> size >> proc;
    vector<int> vet(size);
    for (int i = 0; i < size; i++)
        cin >> vet[i];
    

    cout << (index_of(vet, proc) != -1 ? "sim\n" : "nao\n");
}