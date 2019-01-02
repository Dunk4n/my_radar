/*
** EPITECH PROJECT, 2018
** my_merge
** File description:
** merge
*/

#include "my.h"

void    merge(linked_list_t **begin1, linked_list_t *begin2, int (*cmp)())
{
    concat_list(begin1, begin2);
    sort_list(begin1, (*cmp));
}
