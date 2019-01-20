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

int deletes_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *tmp;
    linked_list_t *delet;

    if (begin == NULL || *begin == NULL)
        return (0);
    tmp = *begin;
    if ((*cmp)(tmp->data, data_ref) == 1) {
        *begin = (*begin)->next;
        free(tmp);
        return (0);
    }
    delet = tmp->next;
    while (delet) {
        if (delet && (*cmp)(delet->data, data_ref) == 1) {
            tmp->next = delet->next;
            free(delet);
            return (0);
        }
        delet = delet->next;
        tmp = tmp->next;
    }
    return (0);
}
