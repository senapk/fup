#include <iostream>

int main() {
    int limite { };
    std::cin >> limite;
    int primeiro = 1;
    int segundo = 1;
    int acc { 0 };
    while (true) {
        int novo = primeiro + segundo;
        if (novo > limite)
            break;
        if (novo % 2 == 0)
            acc += novo;
        primeiro = segundo;
        segundo = novo;
    }
    std::cout << acc << '\n';
}
