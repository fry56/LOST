/*
** EPITECH PROJECT, 2022
** list_pop.c
** File description:
** desc
*/

#include <t_list.h>

void *tlist_pop(t_list *list)
{
    t_list_node *out;

    if (list == NULL || !list->tail)
        return NULL;
    out = list->tail;
    tlist_remove(list, out);
    return out->value;
}
