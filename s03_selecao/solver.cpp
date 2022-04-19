#include <iostream>
using namespace std;

int main() {
    cout << "Quanto dinheiro voce tem: ";
    
    double dinheiro { };
    cin >> dinheiro;

    if (dinheiro < 1.10) {
        cout << "passar fome!\n";
    } else if (dinheiro < 12.0) {
        cout << "vou comer no ru!\n";
    } else if (dinheiro < 50) {
        cout << "vou comer na tia da esquina\n";
    } else {
        cout << "vou comer no rodizio\n";
    }
}