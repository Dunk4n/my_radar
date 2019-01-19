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

    draw_storm(map);
    update_set_tour(map);
    while (++i < map->nb_trans) {
        if (map->trans[i].dead == 0 && map->fg_hitbox == 0) {
            sfRectangleShape_setPosition(map->trans[i].shape,
map->trans[i].pos);
            sfRenderWindow_drawRectangleShape(map->win->window,
map->trans[i].shape, NULL);
        }
        if (map->trans[i].dead == 0 || map->trans[i].tmp > 0)
            j = 1;
    }
    if (j == 0)
        return (1);
    return (0);
}

int     update(my_map_t *map)
{
    int i = 0;

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
    //while (map->fg_sprite == 0 && ++i < map->nb_trans) {
    //    if (map->trans[i].dead == 0)
    //        sfRenderWindow_drawSprite(map->win->window, map->trans[i].sp, NULL);
    //}
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
    int i = 0;
    /*while (map->split[0].tab[i]) {
        printf("dead: [%d], name: [%d]\n", map->split[0].tab[i]->dead,
map->split[0].tab[i]->name);
        i++;
    }
    printf("tab2\n");
    i = 0;
    while (map->split[1].tab[i]) {
        printf("dead: [%d], name: [%d]\n", map->split[1].tab[i]->dead,
map->split[1].tab[i]->name);
        i++;
    }*/

    map->clock = sfClock_create();
    map->fgt = sfTime_asMilliseconds(sfClock_getElapsedTime(map->clock));
    map->fgk = sfTime_asMilliseconds(sfClock_getElapsedTime(map->clock));
    while (sfRenderWindow_isOpen(map->win->window)) {
        make_time(map);
        if (update(map) == 1)
            sfRenderWindow_close(map->win->window);
        check(map);
    }

    /*printf("-----------------------\n");
    i = 0;
    while (map->split[0].tab[i]) {
        printf("dead: [%d], name: [%d]\n", map->split[0].tab[i]->dead,
map->split[0].tab[i]->name);
        i++;
    }
    printf("tab2\n");
    i = 0;
    while (map->split[1].tab[i]) {
        printf("dead: [%d], name: [%d]\n", map->split[1].tab[i]->dead,
map->split[1].tab[i]->name);
        i++;
    }*/
    return (0);
}
