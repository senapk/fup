#define XPAINT
#include <xpaint.h>

int main() {
    x_open(800, 600, "figura");
    auto yellow = x_color_make(200, 243, 125, 255);
    x_color_set(yellow);
    x_clear();
    x_color_set(WHITE);
    x_fill_circle(200, 200, 50);
    x_save();
    x_close();
}