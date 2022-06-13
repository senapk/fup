#include <iostream>
#include <vector>

//criando atalho
//matriz é um vector de vector de inteiros
using matriz = std::vector<std::vector<int>>;

void read(matriz& mat);
void show(matriz  mat);

int main() {
    int nl { }, nc { };
    std::cin >> nl >> nc;

    std::vector<int> linha(nc); //a linha tem nc elementos
    matriz mat(nl, linha);      //a matriz tem nl linhas

    read(mat);
    show(mat);
}

void read(matriz& mat) {
    int nl = mat.size();
    int nc = mat[0].size();
    for (int l = 0; l < nl; l++)
        for (int c = 0; c < nc; c++)
            std::cin >> mat[l][c];
}
void show(matriz  mat) {
    int nl = mat.size();
    int nc = mat[0].size();
    for (int l = 0; l < nl; l++) {
        for (int c = 0; c < nc; c++)
            std::cout << (c == 0 ? "" : " ") << mat[l][c];
        std::cout << "\n"; //quebra de linha no final de cada coluna
    }
}

