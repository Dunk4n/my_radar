/*
** EPITECH PROJECT, 2018
** my_concat_list
** File description:
** concat list
*/

#include <stdlib.h>
#include "my.h"

void    concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *tmp;

    if (begin1 == NULL || *begin1 == NULL)
        return ;
    tmp = *begin1;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = begin2;
}
