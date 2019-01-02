/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** return the number of char in a string
*/

int     my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
