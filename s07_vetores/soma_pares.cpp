#include <iostream>

int main() {
    int a { }, b { };
    std::cin >> a >> b;
    int acc { 0 };
    for (int i { a }; i <= b; i += 1)
        if (i % 2 == 0)
            acc += i;
    std::cout << acc << '\n';
}