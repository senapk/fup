#include <iostream> //jeito c++
#include <cstdio>   //jeito c
#include <iomanip>


int main() {
    char final { '.' };
    int dia { 5 };
    double peso { 1.673321 };
    double valor { 1.9 };

    std::cout << std::fixed;
    std::cout << std::setfill('0');

    auto p2 = std::setprecision(2);
    auto w2 = std::setw(2);

    std::cout << "Hoje, dia "
              << w2 << dia << ", eu comprei " 
              << p2 << peso << "kg de tomate a "
              << p2 << valor << "Rs reais o KG" << final << "\n";
     
    printf("Hoje, dia %02d, eu comprei %.2fkg de tomate a %.2fRs reais o KG%c\n", \
            dia, peso, valor, final);

    std::cout << std::setfill('_') << std::right;

    auto w10 = std::setw(10);
    
    std::cout << w10 << "Josue" << ".\n";
    std::cout << w10 << "Marilia" << ".\n";
    std::cout << w10 << std::setprecision(2) << 4.5677 << '\n';

    printf("%10s\n", "Josue");
    printf("%10s\n", "Marilia");
    printf("%10.2f\n", 4.5677);
}












