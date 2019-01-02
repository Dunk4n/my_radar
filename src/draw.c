/*
** EPITECH PROJECT, 2018
** display
** File description:
** try not to segfault, good luck :)
*/

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

void    hitbox(my_framebuff_t *buff, sfVector2f pos, sfVector2i size,
sfColor color)
{
    int i = 0;
    int j = 0;

    while (i < size.x) {
        j = 0;
        while (j < size.y) {
            ((i < 2 || i > 18) || (j < 2 || j > 18)) ?
put_pixel(buff, pos.x + j, pos.y + i, color) : 0;
            j++;
        }
        i++;
    }
}
