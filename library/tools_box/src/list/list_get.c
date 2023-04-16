/*
** EPITECH PROJECT, 2022
** map_get.c
** File description:
** desc
*/

#include <t_ctype.h>
#include <t_list.h>
#include <t_string.h>

t_list_node *tlist_get(t_list *list, tsize_t index)
{
    tsize_t i = 0;
    if (list == NULL)
        return NULL;
    list_foreach(list, node) {
        if (index == i)
            return node;
        i++;
    }
    return NULL;
}

t_list_node *tlist_find(t_list *list, void *value)
{
    if (list == NULL || value == NULL)
        return NULL;
    list_foreach(list, node) {
        if (node->value == value)
            return node;
    }
    return NULL;
}
