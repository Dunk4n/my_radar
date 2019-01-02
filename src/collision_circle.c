/*
** EPITECH PROJECT, 2018
** collision_circle
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "my.h"
#include "radar.h"

int     col_circle(tour_t *tour, double **cord)
{
    int j = 0;

    while (j < 4) {
        if (pow(cord[0][j] - tour->pos.x - 32, 2) + pow(cord[1][j] -
tour->pos.y - 32, 2) <= pow(tour->rayon, 2))
            return (1);
        j++;
    }
    return (0);
}

double  **assign_cord(sfIntRect rec, float alp)
{
    int p[] = {rec.left + rec.width / 2, rec.top - rec.height / 2};
    double a = alp * M_PI / 180;
    double **cord = malloc(sizeof(double*) * 2);

    cord[0] = malloc(sizeof(double) * 4);
    cord[1] = malloc(sizeof(double) * 4);
    cord[0][0] = (rec.left - p[0]) * cos(a) - (rec.top - p[1]) * sin(a) + p[0];
    cord[0][1] = (rec.left - p[0]) * cos(a) - (rec.top - rec.height - p[1]) *
sin(a) + p[0];
    cord[0][2] = (rec.left + rec.width - p[0]) * cos(a) - (rec.top - p[1]) *
sin(a) + p[0];
    cord[0][3] = (rec.left + rec.width - p[0]) * cos(a) - (rec.top - rec.height
- p[1]) * sin(a) + p[0];
    cord[1][0] = (rec.left - p[0]) * sin(a) + (rec.top - p[1]) * cos(a) + p[1];
    cord[1][1] = (rec.left - p[0]) * sin(a) + (rec.top + rec.height - p[1]) *
cos(a) + p[1];
    cord[1][2] = (rec.left + rec.width - p[0]) * sin(a) + (rec.top - p[1]) *
cos(a) + p[1];
    cord[1][3] = (rec.left + rec.width - p[0]) * sin(a) + (rec.top +
rec.height - p[1]) * cos(a) + p[1];
    return (cord);
}

int     collision_circle(trans_t *trans, my_map_t *map)
{
    int i = 0;
    double **cord = assign_cord(trans->rectp, trans->alp);

    while (i < map->nb_tour) {
        if (col_circle(&(map->tour[i]), cord))
            return (1);
        i++;
    }
    free(cord[0]);
    free(cord[1]);
    free(cord);
    return (0);
}
