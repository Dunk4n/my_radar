/*
** EPITECH PROJECT, 2018
** my_apply_on_matching_nodes
** File description:
** apply on matching nodes
*/

#include <stdlib.h>
#include <my.h>

int     apply_on_matching_nodes(linked_list_t *begin, int (*f)(),
void const *data_ref, int (*cmp)())
{
    if (begin == NULL)
        return (0);
    while (begin != NULL) {
        if ((*cmp)(begin->data, data_ref) == 0)
            (*f)(begin->data);
        begin = begin->next;
    }
    return (0);
}
