/*
** EPITECH PROJECT, 2018
** check
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include "radar.h"
#include "my.h"

int     check_key(my_map_t *map)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(map->clock)) < map->fgk)
        return (0);
    map->fgk = sfTime_asMilliseconds(sfClock_getElapsedTime(map->clock)) + 200;
    if ((map->win->event).key.code == sfKeyL) {
        map->fg_hitbox = (map->fg_hitbox == 1) ? 0 : 1;
        return (1);
    }
    if ((map->win->event).key.code == sfKeyS) {
        map->fg_sprite = (map->fg_sprite == 1) ? 0 : 1;
        return (1);
    }
    return (0);
}

void    check(my_map_t *map)
{
    while (sfRenderWindow_pollEvent(map->win->window, &(map->win->event))) {
        if ((map->win->event).type == sfEvtClosed) {
            sfRenderWindow_close(map->win->window);
            return ;
        }
        if ((map->win->event).key.code == sfKeyEscape) {
            sfRenderWindow_close(map->win->window);
            return ;
        }
        if (check_key(map) == 1)
            return ;
    }
}
