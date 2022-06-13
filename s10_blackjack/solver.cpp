#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream> //stringstream
using namespace std;

//1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
//A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K
string get_nome(int value) {
    string nomes[] = {"", "A", "2", "3", "4", "5", "6",
                      "7", "8", "9", "10", "J", "Q", "K"};
    return nomes[value];
}

// [1,2,11,13,4]
// [A, 2, J, K, 4]
string str(vector<int> mao) {
    stringstream ss; //buffer
    ss << "[";
    for (int i = 0; i < (int) mao.size(); i++)
        ss << (i == 0 ? "" : ",") << setw(2) << get_nome(mao[i]);
    ss << "]";
    return ss.str();
}

int get_valor(int value) {
    if (value == 1)
        return 11;
    if (value > 9)
        return 10;
    return value;
}

int soma(vector<int> cartas) {
    int total { 0 };
    int n_ases { 0 };
    for (int elem : cartas) {
        if (elem == 1)
            n_ases += 1;
        total += get_valor(elem);
    }
    while (total > 21 && n_ases > 0) {
        n_ases -= 1;
        total -= 10;
    }
    return total;
}

int puxar_carta() {
    return rand() % 13 + 1;
}

string resumo(vector<int> cartas) {
    stringstream ss;
    ss << str(cartas) << ": " << soma(cartas);
    return ss.str();
}

void jogar_jogador(vector<int>& jogador) {
    while (true) {
        std::cout << "Player: " << resumo(jogador) << "\n";
        cout << "Escolha 1(Puxar) 2(Parar): ";
        int escolha { };
        cin >> escolha;
        if (escolha == 1)
            jogador.push_back(puxar_carta());
        else if (escolha == 2)
            break;
        if (soma(jogador) > 21)
            break;
    }
}

void jogar_mesa(vector<int>& mesa, vector<int>& jogador) {
    while (true) {
        if (soma(mesa) > 21)
            break;
        if (soma(mesa) >= soma(jogador))
            break;
        getchar();
        mesa.push_back(puxar_carta());
        std::cout << "Dealer: " << resumo(mesa);
    }
}

int main() {
    srand(time(0));
    vector<int> jogador = {puxar_carta(), puxar_carta()};
    vector<int> mesa = {puxar_carta()};
    std::cout << "Dealer: " << resumo(mesa) << "\n";
    jogar_jogador(jogador);
    if (soma(jogador) > 21) {
        std::cout << "Player: " << resumo(jogador) << "\n";
        cout << "Voce perdeu\n";
        return 0;
    }
    jogar_mesa(mesa, jogador);
    if (soma(mesa) > 21) {
        cout << "\nParabens, voce ganhou\n";
    } else {
        cout << "\nTente outra vez\n";
    }

}