#include <iostream>
#include <cstdio>
int main() {
    {
        std::string texto = ".\n.\t.";
        std::cout << texto << std::endl;
    }
    {
        std::string texto = "\\\"";
        std::cout << texto << std::endl;
    }
    {
        std::string texto = "má, mé, mim, mó, mú, mui, múi";
        std::cout << texto << std::endl;
    }
    {
        std::string texto = "um texto legal";
        printf("%s\n", texto.c_str());
    }
}