#include <iostream>
#include <iomanip> //set_precision fixed left right set_fill setw
#include <cstdio> //printf, scanf, puts


int main() {
    int soma { };
    std::cin >> soma;
    if (soma == 0)
        std::cout << "joguem de novo\n";
    else
        std::cout << (char) ((soma - 1) % 26 + 'a') << '\n';    
}