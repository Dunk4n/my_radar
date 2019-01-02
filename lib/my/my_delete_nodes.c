/*
** EPITECH PROJECT, 2018
** my_delete_nodes
** File description:
** delete nodes
*/

#include <stdlib.h>
#include "my.h"

int deletes_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *tmp;
    linked_list_t *delet;

    if (begin == NULL || *begin == NULL)
        return (0);
    tmp = *begin;
    while ((*cmp)(tmp->data, data_ref) == 0) {
        delet = (*begin)->next;
        (*begin)->data = ((*begin)->next)->data;
        (*begin)->next = ((*begin)->next)->next;
        free(delet);
    }
    while (tmp->next != NULL) {
        while ((*cmp)((tmp->next)->data, data_ref) == 0) {
            tmp->next = (tmp->next)->next;
        }
        tmp = tmp->next;
    }
    return (0);
}
