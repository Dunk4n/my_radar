/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** my_split_whites_spaces
*/

#include <stdlib.h>

char    charword(char const *str, int n, int nl, char ch)
{
    int i = 0;
    int sp = 1;
    int nb = 0;
    int let = 0;

    while (str[i] != '\0') {
        if (sp == 1 && str[i] != ch) {
            sp = 0;
            nb++;
        }
        sp = (str[i] == ch) ? 1 : 0;
        let += (str[i] != ch && nb == n) ? 1 : 0;
        if (let == nl)
            return (str[i]);
        i++;
    }
    return ('\0');
}

int     nbchar(char const *str, int n, char ch)
{
    int i = 0;
    int sp = 1;
    int nb = 0;
    int let = 0;

    while (str[i] != '\0') {
        if (sp == 1 && str[i] != ch) {
            sp = 0;
            nb++;
        }
        sp = (str[i] == ch) ? 1 : 0;
        let += (str[i] != ch && nb == n) ? 1 : 0;
        i++;
    }
    return (let);
}

int     nbword(char const *str, char ch)
{
    int i = 0;
    int sp = 1;
    int nb = 0;

    while (str[i] != '\0') {
        if (sp == 1 && str[i] != ch) {
            sp = 0;
            nb++;
        }
        sp = (str[i] == ch) ? 1 : 0;
        i++;
    }
    return (nb);
}

char    **my_str_to_word_array(char const *str, char ch)
{
    int i = 0;
    int j = 0;
    char **tab = malloc(sizeof(char*) * (nbword(str, ch) + 1));

    while (i < nbword(str, ch)) {
        tab[i] = malloc(sizeof(char) * (nbchar(str, i + 1, ch) + 1));
        j = 0;
        while (j < nbchar(str, i + 1, ch)) {
            tab[i][j] = charword(str, i + 1, j + 1, ch);
            j++;
        }
        tab[i][j] = '\0';
        i++;
    }
    tab[i] = 0;
    return (tab);
}
