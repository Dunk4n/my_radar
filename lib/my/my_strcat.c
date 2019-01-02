/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** concat tow string
*/

int     my_strlen(char *str);

char    *my_strcat(char *dest, char const *src)
{
    int  len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[len + 1] = src[i];
    }
    dest[len + i] = '\0';
    return (dest);
}
