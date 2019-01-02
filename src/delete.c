/*
** EPITECH PROJECT, 2018
** delete
** File description:
** try not to segfault, good luck :)
*/

#include "my.h"
#include "radar.h"

void    delete_dead(linked_list_t **begin)
{
    linked_list_t *tmp;
    linked_list_t *next;

    if (begin == NULL || *begin == NULL)
        return ;
    tmp = *begin;
    next = (*begin)->next;
    while (next != NULL) {
        if (((trans_t*)((next)->data))->dead == 1 &&
((trans_t*)((next)->data))->tmp == -1)
            tmp->next = next->next;
        else
            tmp = tmp->next;
        next = next->next;
    }
    if (((trans_t*)((*begin)->data))->dead == 1 &&
((trans_t*)((*begin)->data))->tmp == -1)
        *begin = (*begin)->next;
}
