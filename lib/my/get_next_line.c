/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include <unistd.h>

int     back_slashn(char *buff, int size)
{
    int i = 0;

    while (buff[i] != '\0' && i < size) {
        if (buff[i] == '\0' || buff[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

char    *concat(char *buff, char *line, int size)
{
    int     cnt[] = {0, 0, 0};
    char    *tmp;

    while (line && line[cnt[0]++]);
    size += cnt[0];
    if ((tmp = malloc(size)) == NULL)
        return (NULL);
    while (line && line[cnt[2]]) {
        tmp[cnt[2]] = line[cnt[2]];
        cnt[2]++;
    }
    if (line != NULL)
        free(line);
    while (buff[cnt[1]] && buff[cnt[1]] != '\n') {
        tmp[cnt[2] + cnt[1]] = buff[cnt[1]];
        cnt[1]++;
    }
    if (buff[0] == '\n' && tmp[0] == '\0')
        tmp[cnt[2] + cnt[1]++] = '\n';
    tmp[cnt[2] + cnt[1]] = '\0';
    return (tmp);
}

void    sup_to_n(char *buff)
{
    int i = 0;
    int j = 0;

    while (buff[i] && buff[i++] != '\n');
    while (buff[i]) {
        buff[j] = buff[i];
        i++;
        j++;
    }
    while (buff[j])
        buff[j++] = '\0';
}

char    *to_next_n(char *buff, char *line, int *size)
{
    int i = 0;

    while (buff[i] && buff[i++] != '\n');
    if (i - 1 >= 0 && buff[i - 1] == '\n')
        *size = -1;
    if ((line = malloc(i)) == NULL)
        return (NULL);
    i = 0;
    while (buff[i] && buff[i] != '\n') {
        line[i] = buff[i];
        i++;
    }
    if (i == 0 && buff[0] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

char    *get_next_line(int fd)
{
    static char buff[4096];
    char        *line = NULL;
    int         size = 0;

    if (fd == -1)
        return (NULL);
    line = to_next_n(buff, line, &size);
    while (size >= 0 && back_slashn(buff, size) == -1) {
        size = read(fd, buff, 4095);
        (size != 0) ? line = concat(buff, line, size) : 0;
        size = (size == 0) ? -1 : size;
    }
    sup_to_n(buff);
    size = 0;
    if (line[0] == '\n') {
        line[size] = '\0';
        return (line);
    }
    if (line && line[0] == '\0' && buff[0] == '\0')
        return (NULL);
    return (line);
}
