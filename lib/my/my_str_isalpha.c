/*
** EPITECH PROJECT, 2018
** my_str_isalpha
** File description:
** say if an str is alpha and not number
*/

int     my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] < 97 || str[i] > 'z') && (str[i] < 65 || str[i] > 90))
            return (0);
        i++;
    }
    return (1);
}
