#include <iostream>
#include <cstdlib> //srand rand
#include <ctime> //time
// [min, max[
int random(int min, int max) {
    int qtd = max - min;
    return rand() % qtd + min;
}
int main() {
    srand(time(0));
    int escolhido = random(1, 100);
    int inf = 0, sup = 100;
    while (true) {
        std::cout << "Digite um numero entre ]" << inf << ", " << sup << "[: "; 
        int chute { };
        std::cin >> chute;
        if (chute <= inf || chute >= sup) {
            std::cout << "Sabe ler nao bocó?\n";
            continue;
        }
        if (chute == escolhido) {
            std::cout << "Ninja!\n";
            break;
        } else if (escolhido < chute) {
            std::cout << "eh menor\n";
            sup = chute;
        } else if (escolhido > chute) {
            std::cout << "eh maior\n";
            inf = chute;
        }
        if (sup - inf == 2) {
            std::cout << "voce perdeu\n";
            break;
        }
    }
}