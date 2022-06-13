## Matrizes

[](toc)
- [Matrizes](#matrizes)
- [Lendo e imprimindo.](#lendo-e-imprimindo)
    - [Array](#array)
    - [Vector](#vector)
- [Percorrendo parcialmente a matriz.](#percorrendo-parcialmente-a-matriz)
- [Testando posições e técnicas de percorrimento](#testando-posições-e-técnicas-de-percorrimento)
[](toc)

Matrizes, vetores bidimensionais, podem ser criados em c++ de duas formas, utilizando `array` ou utilizando `vector`.

```cpp
int mat[nl][nc];             //utilizando array

vector<vector<int>> mat;     //utilizando vector
```

O problema de usar `array` é que, internamente, o `C` trata matrizes como vetores. 
Então funções que queiram receber matrizes como parâmetros de funções, precisam saber como
codificar e decodificar matrizes no formato de vetores. Com `vector` isso não acontece.

Com `array`, uma fórmula mágica para saber a posição do elemento linha `l`, coluna `c` é fazer o cálculo
`l * nc + c`.

___
## Lendo e imprimindo.
Seja como entrada o número de linhas e de colunas seguidos dos elementos da matriz, faça o código para ler e escrever a matriz lida.

```txt
>>>>>>>>
3 5
1 2 3 4 5
3 3 7 8 1
8 4 6 5 2
========
1 2 3 4 5
3 3 7 8 1
8 4 6 5 2
<<<<<<<<
```
___
### Array
[](save)[](mat1.cpp)
```cpp
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
```
[](save)

___
### Vector
[](save)[](mat2.cpp)
```cpp
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

```
[](save)


___
## Percorrendo parcialmente a matriz.
Vamos utilizar apenas o modelo de matriz com vector.

Leia um número N, crie uma matriz N x N de zeros e modifique dessa forma:
- coloque o número 3 na diagonal principal, 
- coloque o número 2 na diagonal secundária e
- coloque o número 1 na borda.


```txt
>>>>>>>>
10
========
1 1 1 1 1 1 1 1 1 1
1 3 0 0 0 0 0 0 2 1
1 0 3 0 0 0 0 2 0 1
1 0 0 3 0 0 2 0 0 1
1 0 0 0 3 2 0 0 0 1
1 0 0 0 2 3 0 0 0 1
1 0 0 2 0 0 3 0 0 1
1 0 2 0 0 0 0 3 0 1
1 2 0 0 0 0 0 0 3 1
1 1 1 1 1 1 1 1 1 1
<<<<<<<<
```

Vamos reutilizar parte do código anterior.

[](save)[](mat3.cpp)
```cpp
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

```
[](save)

___
## Testando posições e técnicas de percorrimento
Seja um campo de nl linhas por nc colunas de char preenchidos com valores `.`, `o` e `#`.
- Os `.` representam espaços vazios.
- Os `o` representam animais.
- Os `#` representam àrvores.

Analise todo o campo e marque com X todos os animais estão ao lado de uma árvore.
Ignore as diagonais e considere ao lado como sendo a célula imediatamente acima, abaixo,
esquerda ou direita.

```txt
>>>>>>>>
5 10
..o#..o.##
o.....#..o
.....o....
#o....o#..
.oo....ooo
========
..X#..X.##
o.....#..X
.....o....
#X....X#..
.oo....Xoo
<<<<<<<<
```

Esse problema, para ficar simples exige algumas técnicas:
- de tentar limitar o número de níveis de indentação utilizando funções.
- de como percorrer todos os vizinhos de um pontos.
- de como verificar se o vizinho existe antes de verificar seu valor.

[](save)[](mat4.cpp)
```cpp
#include <iostream>
#include <vector>

//matriz agora é um vector de strings
using matriz = std::vector<std::string>;

struct Pos {
    int l, c;
};

bool is_value(matriz& mat, Pos pos, char value);

std::vector<Pos> neibs(Pos pos);

bool has_tree_near(matriz& mat, Pos pos);

void read(matriz&  mat);

void mark(matriz&  mat);

void show(matriz  mat);

int main() {
    int nl { }, nc { };
    std::cin >> nl >> nc;    
    matriz mat(nl, ""); //nl strings vazias
    read(mat);
    mark(mat);
    show(mat);
}

bool is_value(matriz& mat, Pos pos, char value) {
    int nl = mat.size();
    int nc = mat[0].size();
    auto [pl, pc] = pos;
    if (pl < 0 || pl >= nl || pc < 0 || pc >= nc)
        return false;
    return mat[pl][pc] == value;
}

std::vector<Pos> neibs(Pos pos) {
    auto [pl, pc] = pos;
    return {
        {pl - 1, pc},
        {pl + 1, pc},
        {pl, pc - 1},
        {pl, pc + 1}
    };
}

bool has_tree_near(matriz& mat, Pos pos) {
    for (Pos pos : neibs(pos))
        if (is_value(mat, pos, '#'))
            return true;
    return false;
}

void read(matriz&  mat) {
    for (auto& line : mat)
        std::cin >> line;
}

void mark(matriz&  mat) {
    int nl = mat.size();
    int nc = mat[0].size();
    for (int l = 0; l < nl; l++) {
        for (int c = 0; c < nc; c++) {
            if (mat[l][c] == 'o' && has_tree_near(mat, {l, c})) //eh animal e tem arvore perto
                mat[l][c] = 'X'; //marca o animal
        }
    }
}

void show(matriz  mat) {
    for (auto line : mat)
        std::cout << line << '\n';
}
```
[](save)