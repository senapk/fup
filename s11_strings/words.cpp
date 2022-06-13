#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(string line) {
    vector<string> palavras;
    stringstream ss(line);
    string palavra;
    while (ss >> palavra)
        palavras.push_back(palavra);
    return palavras;
}

int main() {
    string line;
    getline(cin, line);
    auto palavras = split(line);
    for (auto token : palavras)
        std::cout << token << '\n';
}