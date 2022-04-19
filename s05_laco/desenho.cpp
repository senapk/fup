#define XPAINT
#include <xpaint.h>
#include <iostream>

int ref(int value, int lim) {
    value = value % (2 * lim);
    if (value > lim)
        value -= 2 * (value - lim);
    return value;
}

int main() {
    int w {500}, h {500};
    x_open(w, h, "figura");

    auto r = [](int v) {return ref(v, 255);};
    for (int i = 0; i < 360; i += 1) {
        int raio = 200;
        int xd = raio * x_math_cos(i);
        int yd = raio * x_math_sin(i);

        x_color_set(r(i), r(i * i), r(i + i));
        x_draw_line(250, 250, 250 + xd, 250 - yd);

    }
    x_save();
    x_close();
}