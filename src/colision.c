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

double  plus_x(sfIntRect rec, float alp, int ch)
{
    int i = 1;
    double p = rec.left + rec.width / 2;
    double q = rec.top - rec.height / 2;
    double teta = alp * M_PI / 180;
    double cord[] = {(rec.left - p) * cos(teta) - (rec.top - q) * sin(teta) + p,
(rec.left - p) * cos(teta) - (rec.top - rec.height - q) * sin(teta) + p,
(rec.left + rec.width - p) * cos(teta) - (rec.top - q) * sin(teta) + p,
(rec.left + rec.width - p) * cos(teta) - (rec.top - rec.height - q) *
sin(teta) + p};

    while (i < 4) {
        if (ch == 0 && cord[i] < cord[0])
            cord[0] = cord[i];
        if (ch == 1 && cord[i] > cord[0])
            cord[0] = cord[i];
        i++;
    }
    return (cord[0]);
}

double  plus_y(sfIntRect rec, float alp, int ch)
{
    int i = 1;
    double p = rec.left + rec.width / 2;
    double q = rec.top - rec.height / 2;
    double teta = alp * M_PI / 180;
    double cord[] = {(rec.left - p) * sin(teta) + (rec.top - q) * cos(teta) + q,
(rec.left - p) * sin(teta) + (rec.top + rec.height - q) * cos(teta) + q,
(rec.left + rec.width - p) * sin(teta) + (rec.top - q) * cos(teta) + q,
(rec.left + rec.width - p) * sin(teta) + (rec.top + rec.height - q) *
cos(teta) + q};

    while (i < 4) {
        if (ch == 0 && cord[i] < cord[0])
            cord[0] = cord[i];
        if (ch == 1 && cord[i] > cord[0])
            cord[0] = cord[i];
        i++;
    }
    return (cord[0]);
}

int     is_collision(sfIntRect r1, float alp1, sfIntRect r2, float alp2)
{
    double xp1 = (alp1 == 0) ? r1.left : plus_x(r1, alp1, 0);
    double xg1 = (alp1 == 0) ? r1.left + r1.width : plus_x(r1, alp1, 1);
    double xp2 = (alp2 == 0) ? r2.left : plus_x(r2, alp2, 0);
    double xg2 = (alp2 == 0) ? r2.left + r2.width : plus_x(r2, alp2, 1);

    double yp1 = (alp1 == 0) ? r1.top : plus_y(r1, alp1, 0);
    double yg1 = (alp1 == 0) ? r1.top + r1.height : plus_y(r1, alp1, 1);
    double yp2 = (alp2 == 0) ? r2.top : plus_y(r2, alp2, 0);
    double yg2 = (alp2 == 0) ? r2.top + r2.height : plus_y(r2, alp2, 1);

    if ((xp2 <= xg1 && xg2 >= xp1) && (yp2 <= yg1 && yg2 >= yp1))
        return (1);
    return (0);
}

void    collision(linked_list_t *a, linked_list_t *b, my_map_t *map)
{
    if (((trans_t*)(a->data))->dead == 1 || ((trans_t*)(b->data))->dead == 1)
        return ;
    if (a != b && is_collision(((trans_t*)(a->data))->rectp,
((trans_t*)(a->data))->alp, ((trans_t*)(b->data))->rectp,
((trans_t*)(b->data))->alp) && !collision_circle(((trans_t*)(a->data)), map)
&& !collision_circle(((trans_t*)(b->data)), map)) {
        ((trans_t*)(a->data))->dead = 1;
        ((trans_t*)(b->data))->dead = 1;
    }
}

void    all_collision(my_map_t *map)
{
    int i = 0;
    linked_list_t *a;
    linked_list_t *b;

    while (i < SP) {
        a = (map->split[i]).list;
        while (a != NULL) {
            b = (map->split[i]).list;
            while (b != NULL) {
                collision(a, b, map);
                b = b->next;
            }
            a = a->next;
        }
        delete_dead(&((map->split[i]).list));
        i++;
    }
}
