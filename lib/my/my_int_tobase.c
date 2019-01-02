/*
** EPITECH PROJECT, 2018
** int_tobase
** File description:
** int_tobase
*/

#include <stdlib.h>

int     my_strlen(char const *str);

char    *my_int_tobase(int nb, char *base)
{
    int i = 0;
    int nbt = nb;
    char *res;

    while (nbt != 0) {
        nbt /= my_strlen(base);
        i++;
    }
    res = malloc(i);
    while (--i >= 0) {
        res[i] = base[nb % my_strlen(base)];
        nb /= my_strlen(base);
    }
    return (res);
}
