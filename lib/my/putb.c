/*
** EPITECH PROJECT, 2018
** putb
** File description:
** put binaire
*/

#include <stdarg.h>
#include "my.h"

int     putb(va_list list)
{
    char base[] = "01";

    return (my_putstr(my_int_tobase(va_arg(list, int), base)));
}

int     putch(va_list list)
{
    int c = (my_putchar(va_arg(list, int)));
    return (c);
}

int     puto(va_list list)
{
    char base[] = "01234567";

    return (my_putstr(my_int_tobase(va_arg(list, int), base)));
}

int     putstr(va_list list)
{
    return (my_putstr(va_arg(list, char *)));
}

int     putx(va_list list)
{
    char base[] = "0123456789abcdef";

    return (my_putstr(my_int_tobase(va_arg(list, int), base)));
}
