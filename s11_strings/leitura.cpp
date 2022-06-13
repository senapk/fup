#include <iostream>
#include <sstream> //stringstream
#include <fstream> //ifstream, ofstream

int main() {
    std::ifstream ifs("input.txt");
    if (!ifs.is_open()) {
        std::cout << "arquivo nao encontrado\n";
        return 1;
    }
    std::string fruta { };
    ifs >> fruta;
    
    std::string lixo { };
    std::getline(ifs, lixo); //tirar o \n
    //char c { };
    //ifs >> std::noskipws >> c >> std::skipws;

    std::string nome { };
    std::getline(ifs, nome, '\n');

    float altura { };
    ifs >> altura;

    int idade { };
    ifs >> idade;

    char tipo { };
    ifs >> tipo;

    std::cout << fruta << "\n" << nome << "\n" 
              << altura << "\n" << idade << '\n' 
              << tipo << '\n';
}