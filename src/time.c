/*
** EPITECH PROJECT, 2018
** time
** File description:
** try not to segfault, good luck :)
*/

#include "radar.h"

void    bordure(trans_t *trans)
{
    if (trans->pos.x + trans->vit.x <= -20)
        trans->pos.x = 1940 + trans->vit.x;
    if (trans->pos.x + trans->vit.x >= 1940)
        trans->pos.x = -20 + trans->vit.x;
    if (trans->pos.y + trans->vit.y <= -20 ||
trans->pos.y + trans->vit.y >= 1100) {
        trans->vit.y *= -1;
        trans->pos.x = (trans->pos.x - LM / 2) * (-1) + LM / 2;
    }
}

void    move_transport(trans_t *trans, int nbt)
{
    int i = 0;

    while (i < nbt) {
        /*if ((trans[i]).dead == 0 && ((ABS((trans[i]).pos.x -
(trans[i]).pos_arv.x) < ABS((trans[i]).pos.x + (trans[i]).vit.x -
(trans[i]).pos_arv.x) || ABS((trans[i]).pos.y - (trans[i]).pos_arv.y) <
ABS((trans[i]).pos.y + (trans[i]).vit.y - (trans[i]).pos_arv.y)) ||
((trans[i]).pos.x == (trans[i]).pos_arv.x && (trans[i]).pos.y ==
(trans[i]).pos_arv.y)))
            (trans[i]).dead = 1;*/
        if ((trans[i]).dead == 0) {
            bordure(&(trans[i]));
            (trans[i]).pos.x += (trans[i]).vit.x;
            (trans[i]).rectp.left = (trans[i]).pos.x;
            (trans[i]).pos.y += (trans[i]).vit.y;
            (trans[i]).rectp.top = (trans[i]).pos.y;
        }
        i++;
    }
}

void    make_time(my_map_t *map)
{
    int i = -1;

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(map->clock)) >= map->fgt) {
        all_collision(map);
        move_transport(map->trans, map->nb_trans);
        map->fgt += 16;
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(map->clock)) >= map->fgd) {
        while (++i < map->nb_trans) {
            if (map->trans[i].tmp == 0)
                map->trans[i].dead = 0;
            map->trans[i].tmp -= (map->trans[i].tmp < 0) ? 0 : 1;
        }
        map->fgd = sfTime_asMilliseconds(sfClock_getElapsedTime(map->clock))
+ 1000;
    }
}
