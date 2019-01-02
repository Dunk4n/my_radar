/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** copier n char from a string into another
*/

char    *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n && dest[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    while (i < n) {
        dest = '\0';
        i++;
    }
    return (dest);
}
