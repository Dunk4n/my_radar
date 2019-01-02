/*
** EPITECH PROJECT, 2018
** set_obj
** File description:
** try not to segfault, good luck :)
*/

#include <fcntl.h>
#include <stdlib.h>
#include "radar.h"
#include "my.h"

const char *img_trans[2] = {"doc/hordzeplin.png", "doc/griffon.png"};

const char *img_tower[2] = {"doc/hod_T.png", "doc/all_T.png"};

int     *nb_obj(char *str, my_map_t *map)
{
    int *tab = malloc(sizeof(int) * 2);
    int fd = open(str, O_RDONLY);
    char *line;

    if (fd == -1)
        return NULL;
    line = get_next_line(fd);
    tab[0] = 0;
    tab[1] = 0;
    while (line) {
        if (line[0] == 'A')
            tab[0]++;
        if (line[0] == 'T')
            tab[1]++;
        line = get_next_line(fd);
    }
    close(fd);
    map->nb_trans = tab[0];
    map->nb_tour = tab[1];
    return (tab);
}

void    set_trans(trans_t *trans, char **line)
{
    int i = nb_str_in_array(line);

    trans->tmp = (i > 7) ? my_getnbr(line[6]) : 0;
    trans->dead = 1;
    trans->tx = sfTexture_create(20, 20);
    trans->sp = sfSprite_create();
    trans->tx = sfTexture_createFromFile(img_trans[rand() % 2], NULL);
    sfSprite_setTexture(trans->sp, trans->tx, sfTrue);
    trans->rect.top = 0;
    trans->rect.left = 0;
    trans->rect.width = 20;
    trans->rect.height = 20;
    trans->pos.x = (i > 7) ? my_getfloat(line[1]) : 0;
    trans->pos.y = (i > 7) ? my_getfloat(line[2]) : 0;
    trans->pos_arv.x = (i > 7) ? my_getfloat(line[3]) : 0;
    trans->pos_arv.y = (i > 7) ? my_getfloat(line[4]) : 0;
    trans->rectp.top = trans->pos.y;
    trans->rectp.left = trans->pos.x;
    trans->rectp.width = 20;
    trans->rectp.height = 20;
    set_vit(trans, line);
}

void    set_tour(tour_t *tour, char **line)
{
    int i = nb_str_in_array(line);

    tour->tx = sfTexture_create(65, 65);
    tour->sp = sfSprite_create();
    tour->tx = sfTexture_createFromFile(img_tower[rand() % 2], NULL);
    sfSprite_setTexture(tour->sp, tour->tx, sfTrue);
    tour->pos.x = (i > 4) ? my_getfloat(line[1]) : 0;
    tour->pos.y = (i > 4) ? my_getfloat(line[2]) : 0;
    tour->rayon = (i > 4) ? my_getnbr(line[3]) : 0;
    tour->rect.top = 0;
    tour->rect.left = 0;
    tour->rect.width = 65;
    tour->rect.height = 65;
}

void    free_str_to_word_array(char **line)
{
    int i = 0;

    while (line[i])
        free(line[i++]);
    free(line);
}

void    set_all_obj(my_map_t *map, char *str)
{
    int cnt[] = {0, 0};
    int *tab = nb_obj(str, map);
    char **line;
    int fd = open(str, O_RDONLY);

    (fd == -1) ? map->trans = NULL : 0;
    if (fd == -1)
        return ;
    map->trans = malloc(sizeof(trans_t) * tab[0]);
    map->tour = malloc(sizeof(tour_t) * tab[1]);
    while (cnt[0] + cnt[1] < tab[0] + tab[1]) {
        line = my_str_to_word_array(get_next_line(fd), ' ');
        if (line[0] && my_strcmp(line[0], "A") == 0)
            set_trans(&(map->trans[cnt[0]++]), line);
        if (line[0] && my_strcmp(line[0], "T") == 0)
            set_tour(&(map->tour[cnt[1]++]), line);
        free_str_to_word_array(line);
    }
    free(tab);
    close(fd);
}
