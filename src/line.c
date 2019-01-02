/*
** EPITECH PROJECT, 2018
** src/line
** File description:
** try not to segfault, good luck :)
*/

#include "radar.h"

void    draw_linex(my_framebuff_t *buff, sfVector2i *pos, int r, sfColor color)
{
    double a = (double)(pos[0].y - pos[1].y) / (double)(pos[0].x - pos[1].x);
    double b = (double)pos[0].y - a * (double)pos[0].x;
    sfVector2f ptr = {pos[0].x, pos[0].y};
    sfVector2i size = {r, r};

    while ((int)ptr.x != pos[1].x) {
        ptr.x += ((ptr.x < (double)pos[1].x) ? 1.0 : -1.0);
        ptr.y = a * ptr.x + b;
        if (r > 1)
            square(buff, ptr, size, color);
        else
            put_pixel(buff, ptr.x, ptr.y, color);
    }
}

void    draw_liney(my_framebuff_t *buff, sfVector2i *pos, int r, sfColor color)
{
    double a = (double)(pos[0].x - pos[1].x) / (double)(pos[0].y - pos[1].y);
    double b = (double)pos[0].x - a * (double)pos[0].y;
    sfVector2f ptr = {pos[0].x, pos[0].y};
    sfVector2i size = {r, r};

    while ((int)ptr.y != pos[1].y) {
        ptr.y += ((ptr.y < (double)pos[1].y) ? 1.0 : -1.0);
        ptr.x = a * ptr.y + b;
        if (r > 1)
            square(buff, ptr, size, color);
        else
            put_pixel(buff, ptr.x, ptr.y, color);
    }
}

void    draw_line(my_framebuff_t *buff, sfVector2i *pos, int r, sfColor color)
{
    if (pos[0].x != pos[1].x)
        draw_linex(buff, pos, r, color);
    if (pos[0].y != pos[1].y)
        draw_liney(buff, pos, r, color);
}
