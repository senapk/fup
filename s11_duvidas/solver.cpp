#include <iostream>

void line(int num, int copos) {
    for (int i = 0; i < copos - num; i++)
        std::cout << '.';

    for (int i = 0; i < num; i++)
        std::cout << (i == 0 ? "" : ".") << copos;

    for (int i = 0; i < copos - num; i++)
        std::cout << '.';
    std::cout << '\n';
}

int main() {
    int copos = { };
    std::cin >> copos;
    for (int i = 1; i <= copos; i++)
        line(i, copos);
}