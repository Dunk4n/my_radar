/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** say if an str is number and not alpha
*/

int     my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}
