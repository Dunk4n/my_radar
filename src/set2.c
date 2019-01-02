/*
** EPITECH PROJECT, 2018
** set2
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include <math.h>
#include "radar.h"
#include "my.h"

void    set_split(my_map_t *map, int i, int z, int j)
{
    int k = 0;

    map->split[i * j + z].rect.top = HM / (SP / j) * i;
    map->split[i * j + z].rect.left = LM / j * z;
    map->split[i * j + z].rect.width = LM / j;
    map->split[i * j + z].rect.height = HM / (SP / j);
    map->split[i * j + z].list = NULL;
    while (k < map->nb_trans) {
        if (is_collision(map->trans[k].rectp, map->trans[k].alp,
map->split[i * j + z].rect, 0))
            put_in_list(&(map->split[i * j + z].list), &(map->trans[k]));
        k++;
    }
}

void    set_all_split(my_map_t *map, int j)
{
    int i = 0;
    int z = 0;

    while (i * j < SP) {
        z = -1;
        while (++z < j) {
            set_split(map, i, z, j);
        }
        i++;
    }
}

void    set_vit(trans_t *trans, char **line)
{
    double a;

    if (nb_str_in_array(line) < 8 ||
my_getfloat(line[1]) == my_getfloat(line[3])) {
        trans->vit.x = 0;
        trans->vit.y = (nb_str_in_array(line) > 7) ? my_getfloat(line[5]) : 0;
        trans->alp = 0;
        return ;
    }
    a = ((my_getfloat(line[2]) - my_getfloat(line[4])) /
(my_getfloat(line[1]) - my_getfloat(line[3])));
    trans->vit.x = my_getfloat(line[5]) / sqrt(1 + pow(a, 2));
    trans->vit.y = trans->vit.x * a;
    trans->alp = 0;
}

int     nb_str_in_array(char **tab)
{
    int i = 0;

    while (tab[i++]);
    return (i);
}
