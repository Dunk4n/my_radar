/*
** EPITECH PROJECT, 2018
** put_float
** File description:
** put_float
*/

#include <stdarg.h>
#include "my.h"

int     put_float(va_list list, int p)
{
    double  nb = va_arg(list, double);
    int     n = 0;

    p = (p > 6 || p < 0) ? 6 : p;
    n += my_put_nbr((int)nb);
    nb -= (int)nb;
    n += my_putchar('.');
    n += my_put_nbr((nb * my_pow(10, p)));
    return (n);
}
