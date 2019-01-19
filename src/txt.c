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

void    set_cord(trans_t *trans)
{
    int i = 0;

    if ((trans->cord = malloc(sizeof(sfVector2f) * 4)) == NULL)
        return ;
    while (i < 4) {
        trans->cord[i] = sfRectangleShape_getPoint(trans->shape, i);
        trans->cord[i].x -= trans->rect.width / 2;
        trans->cord[i].y -= trans->rect.height / 2;
        i++;
    }
}

void    set_rotation(trans_t *trans)
{
    sfVector2f ori = {trans->rect.width / 2, trans->rect.height / 2};
    sfVector2f factors = {trans->rect.width, trans->rect.height};
    sfRectangleShape *shape;

    shape = sfRectangleShape_create();
    sfRectangleShape_setSize(shape, factors);
    sfRectangleShape_setPosition(shape, trans->pos);
    //sfRectangleShape_setFillColor(shape, sfTransparent);
    sfRectangleShape_setTexture(shape, trans->tx, sfTrue);
    sfRectangleShape_setOutlineThickness(shape, 3);
    sfRectangleShape_setOutlineColor(shape, sfRed);
    sfRectangleShape_setRotation(shape, trans->alp);
    sfRectangleShape_setOrigin(shape, ori);
    trans->shape = shape;
    set_cord(trans);
}
