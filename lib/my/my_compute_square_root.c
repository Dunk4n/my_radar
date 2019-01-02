/*
** EPITECH PROJECT, 2018
** my_compute_square_root
** File description:
** return the square root of the argument
*/

int     my_compute_square_root(int nb)
{
    int i = 1;

    if (nb < 0)
        return (0);
    while (i * i != nb && i <= nb / 2) {
        i++;
    }
    if (i * i != nb)
        return (0);
    return (i);
}
