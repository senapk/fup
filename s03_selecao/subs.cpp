#include <iostream>




int main() {
    int num { };
    std::cin >> num;
    
    std::cout << "voce digitou " << (num == 0 ? "zero" : (num == 1 ? "um" : "dois")) << '\n';
}