#include <iostream>
#include <vector>
#include <algorithm>

struct Carta {
    int numero;
    char naipe;
};


int main() {
    std::vector<Carta> baralho;
    baralho.push_back({1, 'c'});
    baralho.push_back({2, 'c'});
    baralho.push_back({3, 'c'});
    baralho.push_back({4, 'c'});
    baralho.push_back({5, 'c'});
    baralho.push_back({6, 'c'});
    baralho.push_back({7, 'c'});
    baralho.push_back({8, 'c'});
    baralho.push_back({9, 'c'});
    baralho.push_back({10, 'c'});
    baralho.push_back({11, 'c'});
    baralho.push_back({12, 'c'});
    baralho.push_back({14, 'c'});


    baralho.push_back({1, 'e'});
    baralho.push_back({2, 'e'});
    baralho.push_back({3, 'e'});
    baralho.push_back({4, 'e'});
    baralho.push_back({5, 'e'});
    baralho.push_back({6, 'e'});
    baralho.push_back({7, 'e'});
    baralho.push_back({8, 'e'});
    baralho.push_back({9, 'e'});
    baralho.push_back({10, 'e'});
    baralho.push_back({11, 'e'});
    baralho.push_back({12, 'e'});
    baralho.push_back({13, 'e'});

    baralho.push_back({1, 'o'}); 
    baralho.push_back({2, 'o'});
    baralho.push_back({3, 'o'});
    baralho.push_back({4, 'o'});
    baralho.push_back({5, 'o'});
    baralho.push_back({6, 'o'});
    baralho.push_back({7, 'o'});
    baralho.push_back({8, 'o'});
    baralho.push_back({9, 'o'});
    baralho.push_back({10, 'o'});
    baralho.push_back({11, 'o'});
    baralho.push_back({12, 'o'});
    baralho.push_back({13, 'o'});

    baralho.push_back({1, 'p'});
    baralho.push_back({2, 'p'});
    baralho.push_back({3, 'p'});
    baralho.push_back({4, 'p'});
    baralho.push_back({5, 'p'});
    baralho.push_back({6, 'p'});
    baralho.push_back({7, 'p'});
    baralho.push_back({8, 'p'});
    baralho.push_back({9, 'p'});
    baralho.push_back({10, 'p'});
    baralho.push_back({11, 'p'});
    baralho.push_back({12, 'p'});
    baralho.push_back({13, 'p'});




    if (baralho.size() != 52) {
        std::cout << "baralho com numero de cartas errado" << std::endl;
        return 1;
    }

    std::vector<Carta> copas;
    std::vector<Carta> espadas;
    std::vector<Carta> ouros;
    std::vector<Carta> paus;

    for (Carta carta : baralho) {
        if (carta.naipe == 'c')
            copas.push_back(carta);
        else if (carta.naipe == 'e')
            espadas.push_back(carta);
        else if (carta.naipe == 'o')
            ouros.push_back(carta);
        else if (carta.naipe == 'p')
            paus.push_back(carta);
        else {
            std::cout << "baralho tem naipe doido" << std::endl;
            return 1;
        }
    }

    if (copas.size() != 13 || espadas.size() != 13 || ouros.size() != 13 || paus.size() != 13) {
        std::cout << "tem algum naipe com cartas erradas" << std::endl;
        return 1;
    }
    std::sort(copas.begin(), copas.end(), [](Carta a, Carta b) { return a.numero < b.numero; });
    std::sort(espadas.begin(), espadas.end(), [](Carta a, Carta b) { return a.numero < b.numero; });
    std::sort(ouros.begin(), ouros.end(), [](Carta a, Carta b) { return a.numero < b.numero; });
    std::sort(paus.begin(), paus.end(), [](Carta a, Carta b) { return a.numero < b.numero; });

    for (int i = 0; i < 13; i++) {
        if (copas[i].numero != i + 1) {
            std::cout << "baralho nao esta com as 13 cartas certinhas" << std::endl;
            return 1;
        }
        if (espadas[i].numero != i + 1) {
            std::cout << "baralho nao esta com as 13 cartas certinhas" << std::endl;
            return 1;
        }
        if (ouros[i].numero != i + 1) {
            std::cout << "baralho nao esta com as 13 cartas certinhas" << std::endl;
            return 1;
        }
        if (paus[i].numero != i + 1) {
            std::cout << "baralho nao esta com as 13 cartas certinhas" << std::endl;
            return 1;
        }
    }
    std::cout << "baralho esta correto" << std::endl;
}