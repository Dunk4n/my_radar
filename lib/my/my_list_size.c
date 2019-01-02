/*
** EPITECH PROJECT, 2018
** my_list_size
** File description:
** return number of element on the list
*/

#include <stdlib.h>
#include "my.h"

int     list_size(linked_list_t const *begin)
{
    int i = 0;
    linked_list_t *tmp;

    if (begin == NULL)
        return (0);
    tmp = malloc(sizeof(*tmp));
    tmp->data = begin->data;
    tmp->next = begin->next;
    while (tmp != NULL) {
        tmp = tmp->next;
        i++;
    }
    return (i);
}
