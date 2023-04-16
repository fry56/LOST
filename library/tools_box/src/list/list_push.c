/*
** EPITECH PROJECT, 2022
** list_push.c
** File description:
** desc
*/

#include <t_list.h>

bool tlist_push(t_list_node *dest, t_list_node *src)
{
    t_list *host = dest->host;

    if (!src)
        return false;
    if (host->length > 0) {
        src->next = dest;
        src->prev = dest->prev;
        dest->prev = src;
    } else {
        tlist_add(host, src->value);
    }
    return true;
}
