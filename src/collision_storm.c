/*
** EPITECH PROJECT, 2018
** src/collision_storm
** File description:
** hey. real programmers use vim
*/

#include "radar.h"
#include "my.h"

int     colls(sfVector2f *tp, sfVector2f *rc, sfVector2f ps)
{
    double a1 = DIV(rc[0].y + ps.y * 2 - rc[2].y, rc[0].x + ps.x * 2 - rc[2].x);
    double b1 = (rc[0].y + ps.y) - a1 * (rc[0].x + ps.x);
    double a2 = DIV(rc[1].y + ps.y * 2 - rc[3].y, rc[1].x + ps.x * 2 - rc[3].x);
    double b2 = (rc[1].y + ps.y) - a2 * (rc[1].x + ps.x);
    double a3 = DIV(tp[0].y - tp[1].y, tp[0].x - tp[1].x);
    double b3 = tp[0].y - a3 * tp[0].x;
    int x1 = DIV(b3 - b1, a1 - a3);
    int x2 = DIV(b3 - b2, a2 - a3);

    if ((PP(rc[0].x, rc[2].x) + ps.x - 2 <= x1 && x1 <= PG(rc[0].x, rc[2].x) +
ps.x + 2 && PP(tp[0].x, tp[1].x) - 2 <= x1 && x1 <= PG(tp[0].x, tp[1].x) + 2 &&
PP(rc[0].y, rc[2].y) + ps.y - 2 <= x1 * a1 + b1 && x1 * a1 + b1 <= PG(rc[0].y,
rc[2].y) + ps.y + 2 && PP(tp[0].y, tp[1].y) - 2 <= x1 * a1 + b1 && x1 * a1 + b1
<= PG(tp[0].y, tp[1].y) + 2) || (PP(rc[1].x, rc[3].x) + ps.x - 2 <= x2 && x2 <=
PG(rc[1].x, rc[3].x) + ps.x + 2 && PP(tp[0].x, tp[1].x) - 2 <= x2 && x2 <=
PG(tp[0].x, tp[1].x) + 2 && PP(rc[1].y, rc[3].y) + ps.y - 2 <= x2 * a2 + b2 &&
x2 * a2 + b2 <= PG(rc[1].y, rc[3].y) + ps.y + 2 && PP(tp[0].y, tp[1].y) - 2 <=
x2 * a2 + b2 && x2 * a2 + b2 <= PG(tp[0].y, tp[1].y) + 2))
        return (1);
    return (0);
}

int     is_scollision(storm_t *st, sfVector2f *rc, sfVector2f ps)
{
    int         i = 1;
    sfVector2f  tmp[2];

    while (i < st->nb_point) {
        tmp[0] = st->pos[i - 1];
        tmp[1] = st->pos[i];
        if (colls(tmp, rc, ps))
            return (1);
        i++;
    }
    tmp[0] = st->pos[0];
    if (colls(tmp, rc, ps))
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
