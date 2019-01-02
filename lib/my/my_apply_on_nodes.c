/*
** EPITECH PROJECT, 2018
** my_apply_on_nodes
** File description:
** apply fonction on node
*/

#include <stdlib.h>
#include "my.h"

int     apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    if (begin == NULL)
        return (0);
    while (begin != NULL) {
        (*f)(begin->data);
        begin = begin->next;
    }
    return (0);
}
