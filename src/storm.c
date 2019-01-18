/*
** EPITECH PROJECT, 2018
** src/storm
** File description:
** hey. real programmers use vim
*/

#include <fcntl.h>
#include <stdlib.h>
#include "radar.h"
#include "my.h"

void    get_nb_storm(my_map_t *map, char *str)
{
    int fd = open(str, O_RDONLY);
    char *line;

    if (fd == -1)
        return ;
    line = get_next_line(fd);
    while (line) {
        if (line[0] == 'S')
            map->nb_storm++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    get_next_line(-1);
}

void    set_storm(my_map_t *map, char **line, int nb)
{
    int i = 0;
    int nb_point = (nb_str_in_array(line) - 2) / 2;

    if (nb_point <= 1 && nb_point % 2 != 0)
        return ;
    map->storm[nb].nb_point = nb_point;
    if ((map->storm[nb].pos = malloc(sizeof(sfVector2f) * nb_point)) == NULL)
        return ;
    while (i < nb_point) {
        map->storm[nb].pos[i].x = my_getnbr(line[i * 2 + 1]);
        map->storm[nb].pos[i].y = my_getnbr(line[i * 2 + 2]);
        i++;
    }
}

void    storm(my_map_t *map, char *str)
{
    char *tmp;
    char **line;
    int  nb = 0;
    int  fd = 0;

    get_nb_storm(map, str);
    fd = open(str, O_RDONLY);
    if ((map->storm = malloc(sizeof(storm_t) * map->nb_storm)) == NULL)
        return ;
    while (nb < map->nb_storm) {
        line = my_str_to_word_array((tmp = get_next_line(fd)), ' ');
        if (line[0] && my_strcmp(line[0], "S") == 0) {
            set_storm(map, line, nb);
            nb++;
        }
        free(tmp);
        free_str_to_word_array(line, NULL, fd, 0);
    }
}
