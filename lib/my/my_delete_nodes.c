/*
** EPITECH PROJECT, 2018
** my_delete_nodes
** File description:
** delete nodes
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "radar.h"

void deletes_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *tmp;
    linked_list_t *delet;

    if (begin == NULL || *begin == NULL)
        return ;
    tmp = *begin;
    if ((*cmp)(tmp->data, data_ref) == 1) {
        *begin = (*begin)->next;
        free(tmp);
        return ;
    }
    delet = tmp->next;
    while (delet) {
        if (delet && (*cmp)(delet->data, data_ref) == 1) {
            tmp->next = delet->next;
            free(delet);
            return ;
        }
        delet = delet->next;
        tmp = tmp->next;
    }
}
