/*
** EPITECH PROJECT, 2018
** src/circle
** File description:
** try not to segfault, good luck :)
*/

#include <math.h>
#include "my.h"
#include "radar.h"

void    draw_circle8(my_framebuff_t *buff, int r, sfVector2i cnt, sfColor color)
{
    int x = 0;
    int y = r;
    int m = 5 - 4 * r;
    while (x <= y) {
        put_pixel(buff, x + cnt.x, y + cnt.y, color);
        put_pixel(buff, y + cnt.x, x + cnt.y, color);
        put_pixel(buff, -x + cnt.x, y + cnt.y, color);
        put_pixel(buff, -y + cnt.x, x + cnt.y, color);
        put_pixel(buff, x + cnt.x, -y + cnt.y, color);
        put_pixel(buff, y + cnt.x, -x + cnt.y, color);
        put_pixel(buff, -x + cnt.x, -y + cnt.y, color);
        put_pixel(buff, -y + cnt.x, -x + cnt.y, color);
        if (m > 0) {
            y--;
            m -= 8 * y;
        }
        x++;
        m += 8 * x + 4;
    }
}

void    draw_blob(my_framebuff_t *buff, sfVector2i cnt, int r, sfColor color)
{
    int     i = cnt.x - r;
    int     j = cnt.y - r;
    sfColor tmp = color;
    double  val = 1;

    while (i <= cnt.x + r) {
        j = cnt.y - r;
        while (j <= cnt.y + r) {
            val = 1 + (cos(sqrt(pow((double)(i - cnt.x) / r, 2) +
pow((double)(j - cnt.y) / r, 2)) / sqrt(2) * M_PI));
            tmp.r = color.r * (val / 2);
            tmp.g = color.g * (val / 2);
            tmp.b = color.b * (val / 2);
            tmp.a = color.a * (val / 2);
            (my_pow(i - cnt.x, 2) + my_pow(j - cnt.y, 2) <= my_pow(r, 2)) ?
put_add_pixel(buff, i, j, tmp) : 0;
            j++;
        }
        i++;
    }
}
