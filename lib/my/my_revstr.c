/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** reverses a string
*/

int      my_strlen(char const *str);

char            *my_revstr(char *str)
{
    int i = 0;
    int len = my_strlen(str) - 1;
    char swap = 0;

    while (i < len / 2) {
        swap = str[i];
        str[i] = str[len - i];
        str[len - i] = swap;
        i++;
    }
    return (str);
}
