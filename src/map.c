/*
** EPITECH PROJECT, 2018
** map
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include "radar.h"

void    clear_buff(my_framebuff_t *buff)
{
    int i = 0;

    while (i < LM * HM) {
        buff->pixels[i * 4] = 0;
        buff->pixels[i * 4 + 1] = 0;
        buff->pixels[i * 4 + 2] = 0;
        buff->pixels[i * 4 + 3] = 0;
        i++;
    }
}

void    update_set_tour(my_map_t *map)
{
    int i = -1;
    sfVector2i tmp = {20, 20};

    if (map->fg_hitbox == 0)
        draw_storm(map);
    while (++i < map->nb_tour) {
        if (map->fg_sprite == 0)
            sfSprite_setPosition(map->tour[i].sp, map->tour[i].pos);
        if (map->fg_hitbox == 0) {
            tmp.x = (int)map->tour[i].pos.x + 32;
            tmp.y = (int)map->tour[i].pos.y + 32;
            draw_circle8(map->win->framebuff, map->tour[i].rayon, tmp, sfGreen);
        }
    }
}

int     update_set_trans(my_map_t *map)
{
    int i = -1;
    int j = 0;

    update_set_tour(map);
    while (++i < map->nb_trans) {
        sfRectangleShape_setFillColor(map->trans[i].shape, (map->fg_sprite == 0)
? sfWhite : sfTransparent);
        sfRectangleShape_setOutlineColor(map->trans[i].shape,
(map->fg_hitbox == 0) ? sfRed : sfTransparent);
        if (map->trans[i].dead == 0) {
            sfRectangleShape_setPosition(map->trans[i].shape,
map->trans[i].pos);
            sfRenderWindow_drawRectangleShape(map->win->window,
map->trans[i].shape, NULL);
        }
        (map->trans[i].dead == 0 || map->trans[i].tmp > 0) ? j = 1 : 0;
    }
    if (j == 0)
        return (1);
    return (0);
}

int     update(my_map_t *map)
{
    int i = 0;

    if (map->fg_hitbox != 0)
        clear_buff(map->win->framebuff);
    sfRenderWindow_clear(map->win->window, sfBlack);
    sfRenderWindow_drawSprite(map->win->window, map->win->sprite, NULL);
    if (update_set_trans(map) == 1)
        return (1);
    sfTexture_updateFromPixels(map->win->txpixel, map->win->framebuff->pixels,
LM, HM, 0, 0);
    sfRenderWindow_drawText(map->win->window, map->txt, NULL);
    while (map->fg_sprite == 0 && i < map->nb_tour)
        sfRenderWindow_drawSprite(map->win->window, map->tour[i++].sp, NULL);
    i = -1;
    sfRenderWindow_drawSprite(map->win->window, map->win->sppixel, NULL);
    sfRenderWindow_display(map->win->window);
    return (0);
}

int     map(char *str)
{
    my_map_t *map = set_map(str);

    if (map == NULL)
        return (84);
    map->time = 0;
    map->clock = sfClock_create();
    map->fgt = sfClock_getElapsedTime(map->clock).microseconds;
    map->fgk = sfClock_getElapsedTime(map->clock).microseconds;
    while (sfRenderWindow_isOpen(map->win->window)) {
        make_time(map);
        if (update(map) == 1)
            sfRenderWindow_close(map->win->window);
        check(map);
    }
    return (0);
}
