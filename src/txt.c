/*
** EPITECH PROJECT, 2018
** src/txt
** File description:
** C-x C-c
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include "my.h"
#include "radar.h"

void    make_txt(my_map_t *map)
{
    char        txt[] = "00000";
    char        *tmp = my_itoa(map->time);
    int         i = 0;
    int         len = my_strlen(tmp);

    map->time++;
    while (i < 5 && len - i >= 0) {
        txt[5 - i] = tmp[len - i];
        i++;
    }
    sfText_setString(map->txt, txt);
}

/*void    set_core_trans_x(trans_t *trans, sfIntRect rec, float alp,
sfVector2i *point)
{
    double p = rec.left + rec.width / 2;
    double q = rec.top - rec.height / 2;
    double teta = alp * M_PI / 180;

    trans->core->nb_point = 4;
    point[0].x = (rec.left - p) * cos(teta) - (rec.top - q) * sin(teta) + p
- trans->pos.x;
    point[1].x = (rec.left - p) * cos(teta) - (rec.top - rec.height - q) *
sin(teta) + p - trans->pos.x;
    point[2].x = (rec.left + rec.width - p) * cos(teta) - (rec.top -
rec.height - q) * sin(teta) + p - trans->pos.x;
    point[3].x = (rec.left + rec.width - p) * cos(teta) - (rec.top - q) *
sin(teta) + p - trans->pos.x;
    trans->core->point = point;
}

void    set_core_trans_y(trans_t *trans, sfIntRect rec, float alp,
sfVector2i *point)
{
    double p = rec.left + rec.width / 2;
    double q = rec.top - rec.height / 2;
    double teta = alp * M_PI / 180;

    point[0].y = (rec.left - p) * sin(teta) + (rec.top - q) * cos(teta) + q
- trans->pos.y;
    point[1].y = (rec.left - p) * sin(teta) + (rec.top + rec.height - q) *
cos(teta) + q - trans->pos.y;
    point[2].y = (rec.left + rec.width - p) * sin(teta) +
(rec.top + rec.height - q) * cos(teta) + q - trans->pos.y;
    point[3].y = (rec.left + rec.width - p) * sin(teta) + (rec.top - q) *
cos(teta) + q - trans->pos.y;
    trans->core->point = point;
}

void    tyuset_rotation(trans_t *trans)
{
    sfVector2f tmp = {trans->rect.width / 2, trans->rect.height / 2};

    if ((trans->core = malloc(sizeof(core_t))) == NULL)
        return ;
    if((trans->core->point = malloc(sizeof(sfVector2f) * 4)) == NULL)
        return ;
    set_core_trans_x(trans, trans->rectp, trans->alp, trans->core->point);
    set_core_trans_y(trans, trans->rectp, trans->alp, trans->core->point);
    //printf("name [%d], 1x: [%d] y: [%d], 2x: [%d] y: [%d], 3x: [%d] y: [%d],\
 4x: [%d] y: [%d]\n\n",
//trans->name, trans->core->point[0].x, trans->core->point[0].y,
//trans->core->point[1].x, trans->core->point[1].y, trans->core->point[2].x,
//trans->core->point[2].y, trans->core->point[3].x, trans->core->point[3].y);
    sfSprite_setOrigin(trans->sp, tmp);
    sfSprite_setRotation(trans->sp, trans->alp);
}*/

void    set_rotation(trans_t *trans)
{
    sfVector2f ori = {trans->rect.width / 2, trans->rect.height / 2};
    sfVector2f factors = {trans->rect.width, trans->rect.height};
    sfRectangleShape *shape;

    shape = sfRectangleShape_create();
    sfRectangleShape_setSize(shape, factors);
    sfRectangleShape_setPosition(shape, trans->pos);
    sfRectangleShape_setFillColor(shape, sfTransparent);
    sfRectangleShape_setOutlineThickness(shape, 3);
    sfRectangleShape_setOutlineColor(shape, sfRed);
    sfRectangleShape_setRotation(shape, trans->alp);
    sfRectangleShape_setOrigin(shape, ori);
    trans->shape = shape;
    sfSprite_setOrigin(trans->sp, ori);
    sfSprite_setRotation(trans->sp, trans->alp);
}
