/*
** EPITECH PROJECT, 2018
** put_ptr
** File description:
** put ptr
*/

#include <stdarg.h>
#include "my.h"

int     putptr(long nb)
{
    char hex[] = "0123456789abcdef";

    if (nb < 10)
        my_putchar(nb + '0');
    else {
        putptr(nb / 16);
        my_putchar(hex[nb % 16]);
    }
    return (0);
}

int     put_ptr(va_list list)
{
    my_putstr("0x");
    putptr(va_arg(list, long));
    return (14);
}

int     no_printable(char c)
{
    int     i = 2;
    char    tab[] = "000";

    my_putchar('\\');
    while (c != 0) {
        tab[i] = c % 8 + '0';
        c /= 8;
        i--;
    }
    my_putstr(tab);
    return (3);
}

int     put_str_nprint(va_list list)
{
    int i = 0;
    int nb = 0;
    char *str = va_arg(list, char *);

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127)
            nb += no_printable(str[i]);
        else
            my_putchar(str[i]);
        i++;
        nb++;
    }
    return (nb);
}
