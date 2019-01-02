/*
** EPITECH PROJECT, 2018
** set
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include "radar.h"
#include "my.h"

void            delete_framebuff(my_framebuff_t *framebuff)
{
    free(framebuff->pixels);
    free(framebuff);
}

my_framebuff_t  *my_framebuff_create(int width, int height)
{
    my_framebuff_t      *buff;

    if ((buff = malloc(sizeof(my_framebuff_t))) == NULL)
        return (NULL);
    if ((buff->pixels = malloc(sizeof(sfUint8) * width * height * 4)) == NULL) {
        free (buff);
        return (NULL);
    }
    buff->width = width;
    buff->height = height;
    return (buff);
}

my_window_t     *set_window(my_window_t *win)
{
    sfVideoMode     video_mode;

    win->texture = sfTexture_create(LM, HM);
    win->sprite = sfSprite_create();
    video_mode.width = LM;
    video_mode.height = HM;
    video_mode.bitsPerPixel = 32;
    win->window = sfRenderWindow_create(video_mode, "radar",
sfFullscreen, NULL);
    //win->texture = sfTexture_createFromFile("doc/AAA.png", NULL);
    sfSprite_setTexture(win->sprite, win->texture, sfTrue);
    sfRenderWindow_setFramerateLimit(win->window, 60);
    if ((win->framebuff = my_framebuff_create(LM, HM)) == NULL)
        return (NULL);
    return (win);
}

my_map_t        *set_map(char *str)
{
    my_map_t *map = malloc(sizeof(my_map_t));
    int j = 1;

    set_all_obj(map, str);
    if (map->trans == NULL) {
        my_printf("wrong file or path file\n");
        free(map);
        return (NULL);
    }
    map->win = malloc(sizeof(my_window_t));
    map->win = set_window(map->win);
    map->split = malloc(sizeof(split_t) * SP);
    while ((SP / j) > j)
        j++;
    set_all_split(map, j);
    map->fg_sprite = 0;
    map->fg_hitbox = 0;
    return (map);
}
