/*
** EPITECH PROJECT, 2018
** my_params_to_list
** File description:
** param to list
*/

#include <stdlib.h>
#include "my.h"

int     put_in_list(linked_list_t **list, void *data)
{
    linked_list_t *element;

    element = malloc(sizeof(*element));
    element->data = data;
    element->next = *list;
    *list = element;
    return (0);
}

linked_list_t   *params_to_list(int ac, char * const *av)
{
    int i = 0;
    linked_list_t *list;

    list = NULL;
    while (i < ac) {
        put_in_list(&list, av[i]);
        i++;
    }
    return (list);
}
