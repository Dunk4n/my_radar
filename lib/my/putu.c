/*
** EPITECH PROJECT, 2018
** my_getunbr
** File description:
** get unsigned int
*/

#include <stdarg.h>
#include "my.h"

int     my_put_unbr(unsigned int nb)
{
    int n = 1;

    if (nb < 10)
        my_putchar(nb + '0');
    else {
        n += my_put_unbr(nb / 10);
        my_putchar(nb % 10 + '0');
    }
    return (n);
}

int     putu(va_list list)
{
    unsigned int nb = va_arg(list, unsigned int);

    return (my_put_unbr(nb));
}

int     putxm(va_list list)
{
    char base[] = "0123456789ABCDEF";

    return (my_putstr(my_int_tobase(va_arg(list, int), base)));
}

int     putd(va_list list)
{
    return (my_put_nbr(va_arg(list, int)));
}
