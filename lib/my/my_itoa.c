/*
** EPITECH PROJECT, 2018
** my_itoa
** File description:
** you're a bad developer
*/

#include <stdlib.h>

char    *my_itoa(int nb)
{
    int i = 0;
    int nbt = nb;
    char *tab;

    if (nb == 0)
        i = 1;
    while (nbt != 0) {
        nbt /= 10;
        i++;
    }
    tab = malloc(i + 1);
    tab[i] = '\0';
    while (i > 0) {
        tab[--i] = nb % 10 + '0';
        nb /= 10;
    }
    return (tab);
}
