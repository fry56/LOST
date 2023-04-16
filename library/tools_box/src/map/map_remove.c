/*
** EPITECH PROJECT, 2022
** map_remove.c
** File description:
** desc
*/

#include <t_map.h>

bool tmap_remove(t_map *map, char *key)
{
    t_map_node *node = tmap_get(map, key);

    if (node == NULL)
        return false;
    if (node->host != map)
        return false;
    if (node == map->head)
        map->head = node->next;
    if (node == map->tail)
        map->tail = node->prev;
    if (node->prev)
        node->prev->next = node->next;
    if (node->next)
        node->next->prev = node->prev;
    node->prev = NULL;
    node->next = NULL;
    map->length--;
    return true;
}
