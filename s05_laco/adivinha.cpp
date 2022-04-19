#include <iostream>
#include <cstdlib> //rand e srand
#include <ctime> //time

int main() {
    srand(time(0));

    int resposta = rand() % 100;
    while (true) {
        std::cout << "Digite um numero: ";
        int value { };
        std::cin >> value;
        if (value == 50)
            continue;
        if (value < resposta)
            std::cout << "o numero eh maior\n";
        else if (value > resposta)
            std::cout << "o numero eh menor\n";
        else {
            std::cout << "voce acertou\n";
            break;
        }
    }
}