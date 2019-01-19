/*
** EPITECH PROJECT, 2018
** display
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include "radar.h"

void    put_pixel(my_framebuff_t *framebuff, int x, int y, sfColor color)
{
    if (x >= framebuff->width || x < 0 || y >= framebuff->height || y < 0)
        return ;
    framebuff->pixels[(framebuff->width * y + x) * 4] = color.r;
    framebuff->pixels[(framebuff->width * y + x) * 4 + 1] = color.g;
    framebuff->pixels[(framebuff->width * y + x) * 4 + 2] = color.b;
    framebuff->pixels[(framebuff->width * y + x) * 4 + 3] = color.a;
}

void    put_add_pixel(my_framebuff_t *framebuff, int x, int y, sfColor color)
{
    int i;
    int j;
    int k;

    if (x > framebuff->width || x < 0 || y > framebuff->height || y < 0)
        return ;
    i = ((double)color.r * ((double)color.a / 255.0)) +
((double)framebuff->pixels[(framebuff->width * y + x) * 4]);
    j = ((double)color.g * ((double)color.a / 255.0)) +
((double)framebuff->pixels[(framebuff->width * y + x) * 4]);
    k = ((double)color.b * ((double)color.a / 255.0)) +
((double)framebuff->pixels[(framebuff->width * y + x) * 4]);
    i = (i > 255) ? 255 : i;
    j = (j > 255) ? 255 : j;
    k = (k > 255) ? 255 : k;
    framebuff->pixels[(framebuff->width * y + x) * 4] = i;
    framebuff->pixels[(framebuff->width * y + x) * 4 + 1] = j;
    framebuff->pixels[(framebuff->width * y + x) * 4 + 2] = k;
    framebuff->pixels[(framebuff->width * y + x) * 4 + 3] = 255;
}

void    square(my_framebuff_t *buff, sfVector2f pos, sfVector2i size,
sfColor color)
{
    int i = 0;
    int j = 0;

    while (i < size.x) {
        j = 0;
        while (j < size.y) {
            put_pixel(buff, pos.x + j, pos.y + i, color);
            j++;
        }
        i++;
    }
}

void    storm_line(storm_t *st, my_map_t *map)
{
    int         i = 1;
    sfVector2f  tmp[2];

    while (i < st->nb_point) {
        tmp[0] = st->pos[i - 1];
        tmp[1] = st->pos[i];
        draw_line(map->win->framebuff, tmp, 3, sfYellow);
        i++;
    }
    tmp[0] = st->pos[0];
    draw_line(map->win->framebuff, tmp, 3, sfYellow);
}

void    draw_storm(my_map_t *map)
{
    int i = 0;

    while (i < map->nb_storm) {
        storm_line(&(map->storm[i]), map);
        i++;
    }
}
