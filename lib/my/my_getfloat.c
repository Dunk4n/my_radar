/*
** EPITECH PROJECT, 2018
** my_getfloat
** File description:
** return the float in a string
*/

#include "my.h"

double  my_getfloat(char const *str)
{
    int     i = 0;
    int     j = 0;
    double  nb = 0;
    double  neg = 1;

    while (str[i] != '\0' && (str[i] <= 32 || str[i] == 43 || str[i] == 45))
        neg = (str[i++] == '-') ? -1 : 1;
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i++] - '0');
        if ((nb > 2147483648 && neg == -1) || (nb > 2147483647 && neg == 1))
            return (0);
    }
    if (str[i++] != '.')
        return (nb * neg);
    while (str[i + j] != 0 && str[i + j] >= '0' && str[i + j] <= '9' && j++ < 8)
        nb += (double)(str[i + j - 1] - '0') / (double)my_pow(10, j);
    return (nb * neg);
}
