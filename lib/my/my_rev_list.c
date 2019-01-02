/*
** EPITECH PROJECT, 2018
** my_rev_list
** File description:
** rev chain list
*/

#include <stdlib.h>
#include "my.h"

void    rev_chain(linked_list_t *act, linked_list_t **begin)
{
    linked_list_t *tmp = act->next;

    if (act->next == NULL) {
        *begin = act;
        return ;
    }
    rev_chain(act->next, begin);
    tmp->next = act;
    act->next = NULL;
}

void    rev_list(linked_list_t **begin)
{
    if (begin == NULL || *begin == NULL)
        return ;
    rev_chain(*begin, begin);
}
