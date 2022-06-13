#include <iostream>

int mod(int valor, int total) {
    valor = valor % total;
    if (valor < 0)
        valor = valor + total;
    return valor;
}

int main() {
    char c1 { }, c2 { };
    std::cin >> c1 >> c2; // d b
    
    std::cout << (char)(mod((c1 - 'a') + (c2 - 'a'), 26) + 'a') << '\n';

    std::cout << (char)(mod((c1 - 'a') - (c2 - 'a'), 26) + 'a') << '\n';

}