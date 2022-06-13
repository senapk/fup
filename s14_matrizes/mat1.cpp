#include <iostream>

void read(int mat[], int nl, int nc);
void show(int mat[], int nl, int nc);

int main() {
    int nl { }, nc { };
    std::cin >> nl >> nc;

    int mat[nl][nc]; //cria matriz como array de nl x nc elementos.

    read(&mat[0][0], nl, nc);   //passa a posição do início da matriz
    show(&mat[0][0], nl, nc);
}

void read(int mat[], int nl, int nc) {
    for (int l = 0; l < nl; l++)
        for (int c = 0; c < nc; c++)
            std::cin >> mat[l * nc + c]; //cin >> mat[l][c];
}
void show(int mat[], int nl, int nc) {
    for (int l = 0; l < nl; l++) {
        for (int c = 0; c < nc; c++)
            std::cout << (c == 0 ? "" : " ") << mat[l * nc + c]; //cout mat[l][c];
        std::cout << "\n"; //quebra de linha no final de cada coluna
    }
}
