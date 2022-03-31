#include <iostream>
#include <cstdio>

int main() {
    char c1 { }, c2 { }, c3 { };
    std::cout << "Digite 3 caracteres: ";
    
    scanf(" %c %c %c", &c1, &c2, &c3);

    std::cout << "Primeiro [" << c1 << "]\n";
    std::cout << "Segundo [" << c2 << "]\n";
    std::cout << "Terceiro [" << c3 << "]\n";
}
