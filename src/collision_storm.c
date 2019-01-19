/*
** EPITECH PROJECT, 2018
** src/collision_storm
** File description:
** hey. real programmers use vim
*/

#include "radar.h"
#include "my.h"

int     colls(sfVector2f *tmp, sfVector2f *rc, sfVector2f ps)
{
    double a1 = ((rc[0].y + ps.y) - (rc[2].y + ps.y)) / (-(rc[2].x + ps.x) -
(rc[0].x + ps.x));
    double b1 = (rc[0].y + ps.y) - a1 * (rc[0].x + ps.x);
    double a2 = (tmp[0].y - tmp[1].y) / (-tmp[1].x - tmp[0].x);
    double b2 = tmp[0].y - a2 * tmp[0].x;
    double x = (b2 - b1) / (a1 - a2);
    double petit = (rc[0].x + ps.x <= rc[2].x + ps.x) ?
(rc[0].x + ps.x) : (rc[2].x + ps.x);
    double grand = (rc[0].x + ps.x > rc[2].x + ps.x) ?
(rc[0].x + ps.x) : (rc[2].x + ps.x);
    /*double x2 = (b2 - ((rc[1].y + ps.y) - a1 * (rc[1].x + ps.x))) / ((((rc[1].y
+ ps.y) - (rc[3].y + ps.y)) / (-(rc[3].x + ps.x) - (rc[1].x + ps.x))) - a2);
    double petit2 = (rc[1].x + ps.x <= rc[3].x + ps.x) ?
(rc[1].x + ps.x) : (rc[3].x + ps.x);
    double grand2 = (rc[1].x + ps.x > rc[3].x + ps.x) ?
(rc[1].x + ps.x) : (rc[3].x + ps.x);*/
    double petit3 = (tmp[0].x <= tmp[1].x) ? tmp[0].x : tmp[1].x;
    double grand3 = (tmp[0].x > tmp[1].x) ? tmp[0].x : tmp[1].x;

//    printf("x: %.1f, p: %.1f, g: %.1f, p3: %.1f, g3: %.1f\n\n",
//            x, petit, grand, petit3, grand3);
    if ((x >= petit && x <= grand && x >= petit3 && x <= grand3)/* ||
(x2 >= petit2 && x2 <= grand2 && x2 >= petit3 && x2 <= grand3)*/) {
        return (1);
    }
    return (0);
}

int     is_scollision(storm_t *st, sfVector2f *r2, sfVector2f p2)
{
    int         i = 1;
    sfVector2f  tmp[2];

    while (i < st->nb_point) {
        tmp[0] = st->pos[i - 1];
        tmp[1] = st->pos[i];
        //printf("X: %.1f, %.1f\n", p2.x, p2.y);
        //printf("i: [%d], %.1f, %.1f\n", i, tmp[0].x, tmp[1].x);
        //if (colls(tmp, r2, p2))
        //    printf("la------------------------------------------------------------------\n");
            //return (1);
        i++;
    }
    tmp[0] = st->pos[0];
    if (colls(tmp, r2, p2))
            return (1);
    return (0);
}

void    all_scollision(my_map_t *map)
{
    int i = 0;
    int j = 0;

    while (i < map->nb_storm) {
        j = 0;
        while (j < map->nb_trans) {
            (is_scollision(&(map->storm[i]), map->trans[j].cord,
map->trans[j].pos)) ? map->trans[j].dead = 1 : 0;
            j++;
        }
        i++;
    }
}
