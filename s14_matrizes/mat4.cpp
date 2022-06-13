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
