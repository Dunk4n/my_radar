/*
** EPITECH PROJECT, 2018
** src/set2
** File description:
** programmers start to count from 0
*/

#include <math.h>
#include <stdlib.h>
#include "radar.h"
#include "my.h"

void    set_rect_split(split_t *sp, int i, int j, int k)
{
    sfVector2f  factors = {LM / j, HM / (SP / j)};
    sfVector2f  pos = {(LM / j) * k, (SP / j != 0) ? (HM / (SP / j)) * i : 0};
    int         o = 0;

    sfRectangleShape *tmp = sfRectangleShape_create();
    sfRectangleShape_setSize(tmp, factors);
    sfRectangleShape_setPosition(tmp, pos);
    sp->pos = pos;
    if ((sp->cord = malloc(sizeof(sfVector2f) * 4)) == NULL)
        return ;
    while (o < 4) {
        sp->cord[o] = sfRectangleShape_getPoint(tmp, o);
        o++;
    }
}

void    set_split(my_map_t *map, int i, int j, int k)
{
    int o = 0;
    int nb = 0;

    set_rect_split(&(map->split[(i * j) + k]), i, j, k);
    map->split[(i * j) + k].tab = malloc(sizeof(trans_t*) *
(map->nb_trans + 100));
    while (o < map->nb_trans) {
        if (is_collision(map->split[(i * j) + k].cord,
map->split[(i * j) + k].pos, map->trans[o].cord, map->trans[o].pos)) {
            map->split[(i * j) + k].tab[nb] = &(map->trans[o]);
            nb++;
        }
        o++;
    }
    map->split[(i * j) + k].tab[nb] = NULL;
}

void    set_all_split(my_map_t *map, int j)
{
    int i = 0;
    int k = 0;

    map->split = malloc(sizeof(split_t) * SP);
    while ((i * (j - 1)) + k < SP) {
        k = 0;
        while (k < j) {
            set_split(map, i, j, k);
            k++;
        }
        i++;
    }
}

void    set_vit(trans_t *trans, char **line)
{
    double a;

    if (nb_str_in_array(line) < 7) {
        trans->vit.x = 0;
        trans->vit.y = 0;
        trans->alp = 0;
        return ;
    }
    a = (my_getfloat(line[4]) - my_getfloat(line[2])) /
((my_getnbr(line[3]) - my_getnbr(line[1]) != 0) ? (my_getfloat(line[3]) -
my_getfloat(line[1])) : 1);
    trans->vit.x = (my_getnbr(line[5]) / sqrt(1 + pow(a, 2))) *
((my_getnbr(line[3]) < my_getnbr(line[1])) ? -1 : 1);
    trans->vit.y = trans->vit.x * a;
    trans->alp = atan2(my_getnbr(line[4]) - my_getnbr(line[2]),
my_getnbr(line[3]) - my_getnbr(line[1])) * 180 / M_PI + 90;
    (trans->alp < 0) ? trans->alp += 360 : 0;
}

int     nb_str_in_array(char **tab)
{
    int i = 0;

    if (!tab)
        return (0);
    while (tab[i++]);
    return (i);
}
