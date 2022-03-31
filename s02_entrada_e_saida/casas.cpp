#include <iostream>
#include <iomanip>

int main() {
    auto juros { 0.112332 }; 
    
    //once
    //cout << fixed;
    auto p2 = std::setprecision(2);

    //setprecision é necessario antes de cada variavel e define o maximo de casas decimais
    //sem o fixed, ele pode colocar menos de 2, porém nunca mais de 2
    std::cout << p2 << juros << '\n';


    //5 caracteres, duas casas decimais, zeros a esquerda
    std::cout << std::setfill('0');
    std::cout << std::setw(5) << p2 << 4.3 << '\n';

    printf("%05.2f\n", 4.1);
}