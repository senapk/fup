#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string to_first_letter(string line) {
    stringstream saida, ss(line);
    string token;
    while (ss >> token) {
        saida << ' ';
        for (int i = 0; i < (int) token.size(); i++) {
            if (i == 0)
                saida << ((char) toupper(token[i]));
            else
                saida << ((char) tolower(token[i]));
        }
    }
    return saida.str().substr(1);
}

int main() {
    string line;
    getline(cin, line);
    std::cout << to_first_letter(line) << '\n';

    // stringstream ss;
    // for(char c : line)
    //     ss << static_cast<char>(toupper(c));
    // auto em_maiusculo = ss.str();
    // std::cout << em_maiusculo << '\n';

}