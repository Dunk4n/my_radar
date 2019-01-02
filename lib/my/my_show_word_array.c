/*
** EPITECH PROJECT, 2018
** my_show_word_array
** File description:
** display the content of an array of word
*/

char    my_putchar(char c);
char    *concat_params(int argc, char **argv);

static void    spword(char c, int *sp)
{
    if (*sp == 0 && c <= ' ') {
        *sp = 1;
        my_putchar('\n');
    }
    else if (c > ' ') {
        *sp = 0;
        my_putchar(c);
    }
}

int     my_show_word_array(char * const *tab)
{
    int     i = 0;
    int     j = 0;
    int     sp = 0;

    while (tab[i] != 0) {
        j = 0;
        while (tab[i][j] != '\0') {
            spword(tab[i][j], &sp);
            j++;
        }
        i++;
    }
    return (0);
}
