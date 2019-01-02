/*
** EPITECH PROJECT, 2018
** convert_base
** File description:
** convert base nbr to other base
*/

#include <stdlib.h>

int     my_strlen(char const *str);
int     my_getnbr_base(char const *str, char const *base);

int     sizetab(int nbr, char const *base)
{
    int i = 0;
    int bas = my_strlen(base);

    if (nbr == 0)
        return (1);
    while (nbr != 0) {
        nbr /= bas;
        i++;
    }
    return (i);
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
    long    nb = my_getnbr_base(nbr, base_from);
    int     neg = 1;
    char    *tab;
    int     j = sizetab(nb, base_to);

    tab = malloc(j + 2);
    if (nb < 0) {
        neg *= -1;
        tab[j + 1] = '\0';
        tab[0] = '-';
        j++;
    }
    else
        tab[j] = '\0';
    while (nb != 0) {
        tab[(j--) - 1] = base_to[(nb % my_strlen(base_to)) * neg];
        nb /= my_strlen(base_to);
    }
    return (tab);
}
