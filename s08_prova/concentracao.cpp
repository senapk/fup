#include <iostream>

int main() {
    int menor { }, maior { };
    std::cin >> menor >> maior;
    std::cout << "[ ";
    for (int a = menor, b = maior; b >= menor; a++, b--)
        std::cout << a << " " << b << ' ';
    std::cout << "]\n";
}