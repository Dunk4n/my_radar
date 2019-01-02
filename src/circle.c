/*
** EPITECH PROJECT, 2018
** src/circle
** File description:
** try not to segfault, good luck :)
*/

#include <math.h>
#include "my.h"
#include "radar.h"

//tab[] = {rayon1, rayon2, 0, demi, 0, demi}
void    draw_circle(my_framebuff_t *buff, sfVector2i cnt, int *tab,
sfColor color)
{
    int i = tab[2] * tab[0];
    int j = tab[4] * tab[0];

    while (i <= tab[3] * tab[0]) {
        j = 0;
        while (j <= tab[5] * tab[0]) {
            (my_pow(cnt.x - tab[0] + j - cnt.x, 2) + my_pow(cnt.y - tab[0] + i -
cnt.y, 2) <= my_pow(tab[0], 2) && my_pow(cnt.x - tab[0] + j - cnt.x, 2) +
my_pow(cnt.y - tab[0] + i - cnt.y, 2) >= my_pow(tab[1], 2)) ? put_pixel(buff,
cnt.x - tab[0] + j, cnt.y - tab[0] + i, color) : 0;
            j++;
        }
        i++;
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
