/*
** EPITECH PROJECT, 2018
** src/collision_storm
** File description:
** hey. real programmers use vim
*/

#include "radar.h"
#include "my.h"

double  plus_xs(storm_t *st, int ch)
{
    int         i = 1;
    double      tmp = st->pos[0].x;

    while (i < st->nb_point) {
        if (ch == 0 && st->pos[i].x < tmp)
            tmp = st->pos[i].x;
        if (ch == 1 && st->pos[i].x > tmp)
            tmp = st->pos[i].x;
        i++;
    }
    return (tmp);
}

double  plus_ys(storm_t *st, int ch)
{
    int         i = 1;
    double      tmp = st->pos[0].y;

    while (i < st->nb_point) {
        if (ch == 0 && st->pos[i].y < tmp)
            tmp = st->pos[i].y;
        if (ch == 1 && st->pos[i].y > tmp)
            tmp = st->pos[i].y;
        i++;
    }
    return (tmp);
}

int     is_scollision(storm_t *st, sfVector2f *r2, sfVector2f p2)
{
    double xp1 = plus_xs(st, 0);
    double xg1 = plus_xs(st, 1);
    double yp1 = plus_ys(st, 0);
    double yg1 = plus_ys(st, 1);

    double xp2 = plus_x(r2, p2, 0);
    double xg2 = plus_x(r2, p2, 1);
    double yp2 = plus_y(r2, p2, 0);
    double yg2 = plus_y(r2, p2, 1);

    if ((xp2 <= xg1 && xg2 >= xp1) && (yp2 <= yg1 && yg2 >= yp1))
        return (1);
    return (0);
}
