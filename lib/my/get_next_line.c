/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int     nb_malloc(int *bsn, char *line, char *buff)
{
    int         size = -1;
    int         i = 0;

    while (line && line[i++]);
    while (buff && buff[++size] && buff[size] != '\n');
    *bsn = (buff && buff[size] == '\n') ? 1 : 0;
    return (i + size + 1);
}

char    *next_line(int fd, char *line, char *buff)
{
    char        *relloc = NULL;
    int         tab[3] = {0, 0, 0};

    if ((relloc = malloc(nb_malloc(&(tab[2]), line, buff))) == NULL)
        return (NULL);
    while (line && line[tab[1]]) {
        relloc[tab[1]] = line[tab[1]];
        tab[1]++;
    }
    while (buff && buff[tab[0]] && buff[tab[0]] != '\n') {
        relloc[tab[1] + tab[0]] = buff[tab[0]];
        tab[0]++;
    }
    relloc[tab[1] + tab[0]] = '\0';
    (line) ? free(line) : 0;
    if (!(tab[2])) {
        tab[0] = read(fd, buff, READ_SIZE);
        buff[tab[0]] = '\0';
        (tab[0] > 0) ? relloc = next_line(fd, relloc, buff) : 0;
    }
    return (relloc);
}

char    *get_next_line(int fd)
{
    static char buff[READ_SIZE];
    char        *line = NULL;
    int         size = 0;
    int         i = -1;
    int         y = 0;

    if (fd == -1) {
        while (buff[y])
            buff[y++] = '\0';
        return (NULL);
    }
    line = next_line(fd, line, buff);
    if (!buff[0] && (!line || !line[0]))
        line = NULL;
    while (buff[size] && buff[size++] != '\n');
    while (buff[++i]) {
        buff[i] = buff[i + size];
        size = ((buff[i + size]) ? size : size - 1);
    }
    return (line);
}
