#include <iostream>
#define XPAINT
#include "xpaint.h"

X_Color preto = x_color_make(0, 0, 0, 255);

void letra_o(int x, int y, int size) {
    x_color_set(WHITE);
    __x_draw_block(x, y, size);
    x_color_set(preto);
    x_draw_circle(x + size * 0.5, y + size * 0.5, size * 0.4);
}

void mickey(int x, int y, int raio) {
    double fator = 0.7;
	x_color_set(BLACK);
    x_fill_circle(x - raio * fator, y - raio * fator, raio * fator);
    x_fill_circle(x + raio * fator, y - raio * fator, raio * fator);
    x_color_set(BLUE);
    x_fill_circle(x, y, raio);
    x_color_set(WHITE);
    fator = 0.3;
    x_fill_circle(x - raio * fator, y - raio * fator, raio * fator);
    x_fill_circle(x + raio * fator, y - raio * fator, raio * fator);
    x_color_set(BLACK);
    x_fill_circle(x - raio * fator, y - raio * fator, raio * fator * 0.6);
    x_fill_circle(x + raio * fator, y - raio * fator, raio * fator * 0.6);
    x_color_set(x_color_make(0, 0, 0, 255));
    x_draw_bezier(x - raio * 0.1, y + raio * 0.2, x - raio * 0.7, y - raio * 0.1, x - raio * 1.5, y);
    x_draw_bezier(x + raio * 0.1, y + raio * 0.2, x + raio * 0.7, y - raio * 0.1, x + raio * 1.5, y);

    x_draw_bezier(x - raio * 0.1, 2 + y + raio * 0.2, x - raio * 0.7, 2 + y - raio * 0.1, x - raio * 1.5, 2 + y);
    x_draw_bezier(x + raio * 0.1, 2 + y + raio * 0.2, x + raio * 0.7, 2 + y - raio * 0.1, x + raio * 1.5, 2 + y);
}

int main() {
	x_open(800, 600, "figura");
    x_set_lock();
    int x {400}, y {300}, raio {200};
    while(true) {
        x_color_set(YELLOW);
        x_clear();
        x += x_math_rand(0, 20) - 10;
        y += x_math_rand(0, 20) - 10;
        raio -= x_math_rand(0, 20) - 10;
        mickey(x, y, raio);
        x_save();
    }
	x_close();
}

