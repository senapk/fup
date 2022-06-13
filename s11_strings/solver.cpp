#include <iostream>
#include <sstream> //stringstream
#include <fstream> //ifstream, ofstream
#include <ctime>

std::string pegar_data() {
    std::stringstream ss;
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    ss << now->tm_mday << '-'
       << (now->tm_mon + 1) << '-'
       << (now->tm_year + 1900) << "\n";
    return ss.str();
}

int main() {
    {
        std::fstream ofs("output.bin", std::ofstream::app | std::ofstream::binary);
        ofs << "Estou com fome\n";
        ofs << "quero comer uma pizza\n";
        ofs << "Ass: David Sena\n";
        ofs << pegar_data() << '\n';

    } //saiu do escopo, ele fecha, finaliza
}