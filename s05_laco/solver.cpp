#include <iostream>
#include <cstdlib> //rand e srand
#include <ctime> //time



int main() {

    int soma { 0 };
    
    while(true) {
        int num { };
        std::cin >> num;
        if (num == 0)
            break;
        soma += num;
    }
    std::cout << soma << '\n';
}