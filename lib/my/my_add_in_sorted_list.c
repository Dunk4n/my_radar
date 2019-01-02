/*
** EPITECH PROJECT, 2018
** my_add_in_sorted_list
** File description:
** add in sorted list
*/

#include "my.h"

void    add_in_sorted_list(linked_list_t **begin, void *data, int (*cmp)())
{
    put_in_list(begin, data);
    sort_list(begin, cmp);
}
