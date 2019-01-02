/*
** EPITECH PROJECT, 2018
** my_showstr
** File description:
** show string
*/

void    my_putchar(char c);

static  void    hex(char c)
{
    char    tab[16] = "0123456789abcdef";

    my_putchar(tab[(c / 16) % 16]);
    my_putchar(tab[c % 16]);
}

int     my_showstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] >= 7 && str[i] <= 13) || str[i] == 0 || str[i] == '\\') {
            my_putchar('\\');
            hex(str[i]);
            i++;
        }
        my_putchar(str[i]);
        i++;
    }
    return (0);
}
