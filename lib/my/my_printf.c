/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include "my.h"

int     char_val(char c)
{
    int i = 0;
    char tab[] = "scboxXdupS";

    if (c == 'i')
        return (6);
    while (tab[i] != '\0') {
        if (tab[i] == c) {
            return (i);
        }
        i++;
    }
    return (-1);
}

int     print_f(va_list list, char *str, int *i)
{
    int n = 0;
    int (*put[10])(va_list list) = {&putstr, &putch, &putb, &puto, &putx,
&putxm, &putd, &putu, &put_ptr, &put_str_nprint};

    *i += (str[*i] == '\0') ? 0 : 1;
    if (char_val(str[*i]) >= 0)
        return (put[char_val(str[*i])](list));
    if (str[*i] == '.' && str[*i + 2] == 'f' && str[*i + 1] >= '0' &&
str[*i + 1] <= '9') {
        ++*i;
        return (put_float(list, str[(++*i) - 1] - '0'));
    }
    n += my_putchar('%');
    n += (str[*i] != '%' && str[*i] != '\0') ? my_putchar(str[*i]): 0;
    return (n);
}

int     my_printf(char *str, ...)
{
    va_list list;
    int nb = 0;
    int i = -1;

    va_start(list, str);
    while (str[++i] != '\0') {
        nb += (str[i] != '%') ? my_putchar(str[i]) : 0;
        if (str[i] == '%')
            nb += print_f(list, str, &i);
    }
    va_end(list);
    return (nb);
}
