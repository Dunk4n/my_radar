/*
** EPITECH PROJECT, 2018
** radar
** File description:
** try not to segfault, good luck :)
*/

#ifndef RADAR_H
#define RADAR_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include "my.h"

const char *img_name[5];

typedef struct  my_framebuff_s
{
    int         width;
    int         height;
    sfUint8     *pixels;
}               my_framebuff_t;

typedef struct  my_window_s
{
    sfRenderWindow      *window;
    sfEvent             event;
    sfTexture           *texture;
    sfSprite            *sprite;
    my_framebuff_t      *framebuff;
    sfTexture           *txpixel;
    sfSprite            *sppixel;
    sfVector2u          pos;
}               my_window_t;

typedef struct  my_transport_s
{
    sfTexture       *tx;
    sfSprite        *sp;
    sfVector2f      pos;
    sfVector2f      pos_arv;
    sfVector2f      vit;
    sfIntRect       rect;
    sfIntRect       rectp;
    sfRectangleShape *shape;
    sfVector2f      *cord;
    float           alp;
    int             dead;
    int             pv;
    int             tmp;
    int             name;
}               trans_t;

typedef struct  storm_s
{
    sfVector2f  *pos;
    int         nb_point;
}               storm_t;

typedef struct  tour_s
{
    sfTexture       *tx;
    sfSprite        *sp;
    sfVector2f      pos;
    sfIntRect       rect;
    int             rayon;
}               tour_t;

typedef struct  split_s
{
    sfVector2f      *cord;
    sfVector2f      pos;
    trans_t         **tab;
}               split_t;

typedef struct  my_map_s
{
    my_window_t     *win;
    sfClock         *clock;
    trans_t         *trans;
    tour_t          *tour;
    split_t         *split;
    storm_t         *storm;
    sfInt64         fgt;
    sfInt64         fgk;
    sfInt64         fgd;
    long int        time;
    sfText          *txt;
    int             nb_trans;
    int             nb_trans_true;
    int             nb_tour;
    int             nb_storm;
    int             fg_sprite;
    int             fg_hitbox;
    int             fg_bullet;
}               my_map_t;

int             map(char *str);
my_map_t        *set_map();
void            check(my_map_t *map);
void    draw_line(my_framebuff_t *buff, sfVector2f *pos, int r, sfColor color);
void    put_pixel(my_framebuff_t *framebuff, int x, int y, sfColor color);
void    put_add_pixel(my_framebuff_t *framebuff, int x, int y, sfColor color);
void    square(my_framebuff_t *buff, sfVector2f pos, sfVector2i size,
sfColor color);
void    draw_circle(my_framebuff_t *buff, sfVector2i cnt, int *tab,
sfColor color);
void    draw_blob(my_framebuff_t *buff, sfVector2i cnt, int r, sfColor color);
int     is_collision(sfVector2f *r1, sfVector2f p1,
sfVector2f *r2, sfVector2f p2);
double  plus_x(sfVector2f *cord, sfVector2f pos, int ch);
double  plus_y(sfVector2f *cord, sfVector2f pos, int ch);
void    set_split(my_map_t *map, int i, int z, int j);
void    set_all_split(my_map_t *map, int j);
sfVector2i *set_circle(void);
void    set_all_obj(my_map_t *map, char *str);
void    make_time(my_map_t *map);
void    all_collision(my_map_t *map);
void    delete_dead(trans_t **tab);
void    set_vit(trans_t *trans, char **line);
int     collision_circle(trans_t *trans, my_map_t *map);
void    hitbox(my_framebuff_t *buff, trans_t *trans, sfColor color);
int     nb_str_in_array(char **tab);
void    draw_circle8(my_framebuff_t *buff, int r, sfVector2i cnt,
sfColor color);
void    set_img(trans_t *trans, char **line, int nb, int name);
void    make_txt(my_map_t *map);
void    set_rotation(trans_t *trans);
void    bullet(my_map_t *map, int name, int bt);
void    free_str_to_word_array(char **line, int *tab, int fd, int nb);
void    storm(my_map_t *map, char *str);
int     is_scollision(storm_t *st, sfVector2f *r2, sfVector2f p2);

# define LM 1920
# define HM 1080

# define NB 1
//seulement un nombre qui n'est pas un nombre premier
# define SP 2

#endif
