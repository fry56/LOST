/*
** EPITECH PROJECT, 2022
** map_remove.c
** File description:
** desc
*/

#include <t_list.h>
#include <stdlib.h>

bool tlist_remove(t_list *list, t_list_node *node)
{
    if (node->host != list)
        return false;
    if (node == list->head)
        list->head = node->next;
    if (node == list->tail)
        list->tail = node->prev;

    if (node->prev)
        node->prev->next = node->next;
    if (node->next)
        node->next->prev = node->prev;

    node->prev = NULL;
    node->next = NULL;
    list->length--;
    return true;
}
