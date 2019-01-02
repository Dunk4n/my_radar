/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** allocates memory and copies
*/

#include <stdlib.h>

int     my_strlen(char const *str);

char    *my_strdup(char const *src)
{
    char    *dest = malloc(my_strlen(src));
    int     i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
