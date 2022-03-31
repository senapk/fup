#include <iostream>
#include <iomanip>

using namespace std;
int main() {
    int hora {5}, minuto {1};
    //once
    cout << setfill('0');
    
    //every
    cout << setw(2) << hora << ":" << setw(2) << minuto << endl;
    
    string nome {"Joao"};
    
    //once
    cout << setfill('_') << std::left;;

    //atalho
    auto s10 = setw(10);

    cout << s10 << "Joao" << endl;
    cout << s10 << "Jordana" << endl;

    return 0;
}
