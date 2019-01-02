/*
** EPITECH PROJECT, 2018
** my_strncat
** File description:
** concat tow string
*/

int     my_strlen(char *str);

char    *my_strncat(char *dest, char const *src, int nb)
{
    int  len = my_strlen(dest);
    int i = 0;

    while (i < nb && src[i] != '\0') {
        dest[len + 1] = src[i];
    }
    dest[len + i] = '\0';
    return (dest);
}
