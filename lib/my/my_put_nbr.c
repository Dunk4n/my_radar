/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** display number
*/

int     my_putchar(char c);

int     my_put_nbr(int nb)
{
    int n = (nb < 0) ? my_putchar('-') : 0;

    if (nb > 9 || nb < -9) {
        n += my_put_nbr((nb < 0) ? (-(nb / 10)) : (nb / 10));
        n += my_putchar(((nb < 0) ? (-(nb % 10)) : (nb % 10)) + '0');
        return (n);
    }
    n += my_putchar(((nb < 0) ? (-nb) : nb) + '0');
    return (n);
}
