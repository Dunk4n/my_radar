/*
** EPITECH PROJECT, 2018
** my_getnbr_base
** File description:
** converts and retuns a number in a given base into a decimal number
*/

int     len(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int     power_rec(int nb, int p)
{
    long lnb = 0;

    if (p == 0)
        return (1);
    if (p < 0 || nb == 0)
        return (0);
    lnb = power_rec(nb, p - 1);
    lnb *= nb;
    if (lnb > 2147483647 || lnb < -2147483648)
        return (0);
    return (lnb);
}

int     toint(char c, char const *base, long *nb, int neg)
{
    int     j = 0;
    int     max = 2147483647;

    while (c != base[j] && base[j] != '\0')
        j++;
    if (*nb * len(base) + (j * neg) > max ||
*nb * len(base) + (j * neg) < max + 1) {
        *nb = 0;
        return (0);
    }
    *nb = (*nb * len(base)) + (j * neg);
    return (1);
}

void    normelap(char const *str, char const *base, int *i, int *bol)
{
    int j = 0;
    while (base[j] != '\0') {
        if (str[*i] == base[j++])
            *bol = 1;
    }
}

int     my_getnbr_base(char const *str, char const *base)
{
    long    nb = 0;
    int     i = 0;
    int     neg = 1;
    int     bol = 1;

    while (str[i] != 0 && (str[i] <= ' ' || str[i] == '-' || str[i] == '+')) {
        if (str[i++] == '-')
            neg *= -1;
    }
    while (bol == 1 && str[i] != '\0') {
        bol = 0;
        normelap(str, base, &i, &bol);
        if (bol == 1)
            bol = toint(str[i++], base, &nb, neg);
    }
    return (nb);
}
