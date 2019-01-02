/*
** EPITECH PROJECT, 2018
** my_str_isprintable
** File description:
** if the string is only printable char
*/

int     my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < ' ' || str[i] == 127)
            return (0);
        i++;
    }
    return (1);
}
