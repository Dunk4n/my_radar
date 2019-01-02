/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** return the number in a string
*/

int     my_getnbr(char const *str)
{
    int     i = 0;
    long    nb = 0;
    int     neg = 1;

    while (str[i] != '\0' && (str[i] <= 32 || str[i] == 43 || str[i] == 45)) {
        if (str[i] == '-')
            neg *= -1;
        i++;
    }
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i++] - '0');
        if ((nb > 2147483648 && neg == -1) || (nb > 2147483647 && neg == 1))
            return (0);
    }
    return (nb * neg);
}
