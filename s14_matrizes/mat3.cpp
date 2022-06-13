#include <iostream>
#include <vector>

//criando atalho
//matriz é um vector de vector de inteiros
using matriz = std::vector<std::vector<int>>;

void fill(matriz& mat); //preenche a matriz
void show(matriz  mat);

int main() {
    int dim { };
    std::cin >> dim;
    matriz mat(dim, std::vector<int>(dim)); //forma compactada

    fill(mat);
    show(mat);
}

void fill(matriz& mat) {
    int nl = mat.size();
    int nc = mat[0].size();
    //diagonal principal
    for (int i = 0; i < nl; i++)
        mat[i][i] = 3;

    //diagonal secundária
    for (int i = 0; i < nl; i++)
        mat[i][nc - i - 1] = 2;

    //borda esquerda e direita
    //andando nas linhas e travando as colunas
    for (int l = 0; l < nl; l++) {
        mat[l][0] = 1;
        mat[l][nc - 1] = 1;   
    }

    //borda superior e inferior
    //andando nas colunas e travando as linhas
    for (int c = 0; c < nc; c++) {
        mat[0][c] = 1;
        mat[nl - 1][c] = 1;   
    }
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

