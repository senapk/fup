#include <iostream>

int soma(int a, int b) {
    return a + b;
}

int main() {
    int d { 7 };
    int c = soma(d, 5);
    std::cout << c << '\n';
}