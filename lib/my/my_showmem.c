/*
** EPITECH PROJECT, 2018
** my_showmem
** File description:
** show memory
*/

void    my_putchar(char c);
void    my_putstr(char const *str);

static void    putstr16(char const *str)
{
    int i = 0;

    while (i < 16 && str[i] != '\0') {
        if (str[i] >= ' ' || str[i] < 127)
            my_putchar(str[i]);
        else
            my_putchar('.');
        i++;
    }
    while (i < 16) {
        my_putchar('.');
        i++;
    }
    my_putchar('\n');
}

static void    to_hex(char const *str)
{
    int     i = 7;
    long    nb = (long)str;
    char    hex[16] = "0123456789abcdef";
    char    tex[8];

    while (i >= 0) {
        tex[i] = hex[nb % 16];
        nb /= 16;
        i--;
    }
    while (i < 8) {
        my_putchar(tex[i]);
        i++;
    }
    my_putchar(':');
    my_putchar(' ');
}

static void    char_to_hex(char c)
{
    char t[17] = "0123456789abcdef";

    my_putchar(t[c / 16]);
    my_putchar(t[c % 16]);
}

int     my_showmem(char const *str, int size)
{
    int i = 0;
    int y = 0;

    (void)size;
    while (str[i] != '\0') {
        if (i % 16 == 0 && i != 0)
            putstr16(&str[i - 16]);
        if (i % 16 == 0)
            to_hex(&str[i]);
        char_to_hex(str[i]);
        if ((i++) % 2 != 0)
            my_putchar(' ');
    }
    while ((i + y) % 16 != 0) {
        if ((i + (y++)) % 2 != 0)
            my_putchar(' ');
        my_putstr("  ");
    }
    if (i != 0)
        putstr16(&str[(i + y) - 16]);
    return (0);
}
