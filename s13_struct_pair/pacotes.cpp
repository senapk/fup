#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Pedra {
    int a, b;
};

struct Point {
    double x, y;
};

Point calcular_ponto_do_meio(Point a, Point b) {
    // Point meio;
    // meio.x = (a.x + b.x) / 2;
    // meio.y = (a.y + b.y) / 2;
    // return meio;

    return {(a.x + b.x) / 2, (a.y + b.y) / 2};
}

int main() {
    auto& sf = std::fixed;
    auto& sp = std::setprecision;

    auto& calc_middle = calcular_ponto_do_meio;
    
    std::cout << sf << sp << 3.4567787;
}
