/*
** EPITECH PROJECT, 2018
** src/bullet
** File description:
** don't forget to free at the end
*/

#include <math.h>
#include "radar.h"

void    set_bullet_vit(trans_t *trans, sfVector2f pos, sfVector2f posa,
int name)
{
    double a;

    trans->name = name;
    trans->tx = sfTexture_createFromFile("doc/boulet.png", NULL);
    trans->rect.width = 10;
    trans->rect.height = 10;
    trans->rectp.width = 10;
    trans->rectp.height = 10;
    trans->pv = 1;
    trans->alp = 0;
    if (pos.x == posa.x) {
        trans->vit.x = 0;
        trans->vit.y = 10;
        return ;
    }
    a = (ABS(pos.y - posa.y) / ABS(pos.x - posa.x));
    trans->vit.x = ((pos.x - posa.x < 0) ? 1 : -1) * 5 / sqrt(1 + pow(a, 2));
    trans->vit.y = ((pos.y - posa.y < 0) ? 1 : -1) * ABS(trans->vit.x) * a;
}

void    set_bullet(trans_t *trans, sfVector2f pos, sfVector2f posa, int name)
{
    trans->tmp = 0;
    trans->dead = 1;
    trans->tx = sfTexture_create(10, 10);
    set_bullet_vit(trans, pos, posa, name);
    trans->rect.top = 0;
    trans->rect.left = 0;
    trans->pos.x = pos.x;
    trans->pos.y = pos.y;
    trans->pos_arv.x = posa.x;
    trans->pos_arv.y = posa.y;
    trans->rectp.left = trans->pos.x;
    trans->rectp.top = trans->pos.y;
    set_rotation(trans);
}

int     nb_bullet(my_map_t *map)
{
    int i = map->nb_trans_true;

    while(i < map->nb_trans) {
        if (map->trans[i].dead == 1)
            return (i);
        i++;
    }
    map->nb_trans++;
    return (map->nb_trans - 1);
}

void    bullet(my_map_t *map, int name, int bt)
{
    sfVector2f  pos = {map->trans[name].pos.x -
(map->trans[name].rect.width / 2) - 20, map->trans[name].pos.y};
    sfVector2f  posa = {map->trans[name].pos.x -
map->trans[name].rect.width / 2 - 20 - 500, map->trans[name].pos.y};
    int         nb = nb_bullet(map);

    if (nb >= map->nb_trans_true + 100 || nb < 0)
        return ;
    map->fg_bullet = 3;
    set_bullet(&(map->trans[nb]), pos, posa, nb);
}
