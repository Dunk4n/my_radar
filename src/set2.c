/*
** EPITECH PROJECT, 2018
** src/set2
** File description:
** programmers start to count from 0
*/

#include <math.h>
#include "radar.h"
#include "my.h"

void    set_split(my_map_t *map, int i, int j, int k)
{
    int o = 0;
    int nb = 0;

    map->split[(i * (j - 1)) + k].rect.left = (LM / j) * k;
    if (i == 0)
        map->split[(i * (j - 1)) + k].rect.top = 0;
    else
        map->split[(i * (j - 1)) + k].rect.top = (HM * (SP / j)) / i;
    map->split[(i * (j - 1)) + k].rect.width = (LM / j);
    map->split[(i * (j - 1)) + k].rect.height = (HM / (SP / j));
    map->split[(i * (j - 1)) + k].tab = malloc(sizeof(trans_t*) *
(map->nb_trans + 100));
    while (o < map->nb_trans) {
        if (is_collision(map->split[(i * (j - 1)) + k].rect, 0,
map->trans[o].rectp, map->trans[o].alp)) {
            map->split[(i * (j - 1)) + k].tab[nb] = &(map->trans[o]);
            nb++;
        }
        o++;
    }
    map->split[(i * (j - 1)) + k].tab[nb] = NULL;
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
    trans->vit.x = my_getnbr(line[5]);
    trans->vit.y = 0;
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
