/*
** EPITECH PROJECT, 2018
** my_sort_list
** File description:
** sort list
*/

#include <stdlib.h>
#include "my.h"

int     swap_ele(linked_list_t **ele1, linked_list_t **ele2, int (*cmp)())
{
    linked_list_t tmp;

    tmp.data = (*ele1)->data;
    if ((*cmp)((*ele1)->data, (*ele2)->data) > 0) {
        (*ele1)->data = (*ele2)->data;
        (*ele2)->data = tmp.data;
        return (1);
    }
    return (0);
}

void    sort_list(linked_list_t **begin, int (*cmp)())
{
    int bol = 1;
    linked_list_t *fix = *begin;

    if (begin == NULL || *begin == NULL)
        return ;
    while (bol >= 1) {
        bol = 0;
        fix = *begin;
        while (fix->next != NULL) {
            bol += swap_ele(&fix, &(fix->next), (*cmp));
            fix = fix->next;
        }
    }
}
