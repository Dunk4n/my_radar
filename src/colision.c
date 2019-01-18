/*
** EPITECH PROJECT, 2018
** colision
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "my.h"
#include "radar.h"

double  plus_x(sfVector2f *cord, sfVector2f pos, int ch)
{
    int         i = 1;
    double      tmp = cord[0].x + pos.x;

    while (i < 4) {
        if (ch == 0 && cord[i].x + pos.x < tmp)
            tmp = cord[i].x + pos.x;
        if (ch == 1 && cord[i].x + pos.x > tmp)
            tmp = cord[i].x + pos.x;
        i++;
    }
    return (tmp);
}

double  plus_y(sfVector2f *cord, sfVector2f pos, int ch)
{
    int         i = 1;
    double      tmp = cord[0].y + pos.y;

    while (i < 4) {
        if (ch == 0 && cord[i].y + pos.y < tmp)
            tmp = cord[i].y + pos.y;
        if (ch == 1 && cord[i].y + pos.y > tmp)
            tmp = cord[i].y + pos.y;
        i++;
    }
    return (tmp);
}

int     is_collision(sfVector2f *r1, sfVector2f p1,
sfVector2f *r2, sfVector2f p2)
{
    double xp1 = plus_x(r1, p1, 0);
    double xg1 = plus_x(r1, p1, 1);
    double xp2 = plus_x(r2, p2, 0);
    double xg2 = plus_x(r2, p2, 1);
    double yp1 = plus_y(r1, p1, 0);
    double yg1 = plus_y(r1, p1, 1);
    double yp2 = plus_y(r2, p2, 0);
    double yg2 = plus_y(r2, p2, 1);

    if ((xp2 <= xg1 && xg2 >= xp1) && (yp2 <= yg1 && yg2 >= yp1))
        return (1);
    return (0);
}

void    collision(trans_t *a, trans_t *b, my_map_t *map)
{
    if (a->dead == 1 || b->dead == 1 || a->name == b->name)
        return ;
    if (is_collision(a->cord, a->pos, b->cord, b->pos) &&
!collision_circle(a, map) && !collision_circle(b, map)) {
        a->pv -= 1;
        b->pv -= 1;
        if (a->pv == 0)
            a->dead = 1;
        if (b->pv == 0)
            b->dead = 1;
    }
}

void    all_collision(my_map_t *map)
{
    int i = 0;
    int a = 0;
    int b = 0;

    while (i < SP) {
        a = 0;
        while (map->split[i].tab[a] != NULL) {
            b = 0;
            while (map->split[i].tab[b] != NULL) {
                collision(map->split[i].tab[a], map->split[i].tab[b], map);
                b++;
            }
            a++;
        }
        i++;
    }
}
