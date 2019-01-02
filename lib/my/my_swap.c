/*
** EPITECH PROJECT, 2018
** my_swap
** File description:
** swap tow int
*/

void    my_swap(int *a, int *b)
{
    *a += *b;
    *b = *a - *b;
    *a = *a - *b;
}
