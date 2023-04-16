/*
** EPITECH PROJECT, 2022
** list_clear.c
** File description:
** desc
*/

#include <t_list.h>
#include <stdlib.h>

void tlist_clear(t_list *list)
{
    t_list_node *node, *next;

    if (list == NULL)
        return;
    node = list->head;
    while (node) {
        next = node->next;
        free(node);
        node = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}

void tlist_free(t_list *list)
{
    if (list == NULL)
        return;
    list_foreach(list, node)
        free(node->value);
    tlist_clear(list);
    free(list);
}
