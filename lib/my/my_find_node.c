/*
** EPITECH PROJECT, 2018
** my_apply_on_matching_nodes
** File description:
** apply on matching nodes
*/

#include <stdlib.h>
#include "my.h"

linked_list_t   *find_node(linked_list_t const *begin,
void const *data_ref, int (*cmp)())
{
    linked_list_t tmp;
    linked_list_t *p;

    if (begin == NULL)
        return (NULL);
    tmp = *begin;
    p = &tmp;
    while (p != NULL) {
        if ((*cmp)(p->data, data_ref) == 0)
            return (p);
        p = p->next;
    }
    return (NULL);
}
