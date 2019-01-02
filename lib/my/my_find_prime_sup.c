/*
** EPITECH PROJECT, 2018
** my_find_prime_sup
** File description:
** find the next prime
*/

static int      my_prime(int nb)
{
    int i = 2;

    if (nb < 2)
        return (0);
    while (i <= nb / i) {
        if (nb % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int             my_find_prime_sup(int nb)
{
    int i = 0;

    while (my_prime(nb + i) == 0) {
        i++;
    }
    return (nb + i);
}
