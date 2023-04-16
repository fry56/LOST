/*
** EPITECH PROJECT, 2022
** map_set.c
** File description:
** desc
*/

#include <t_map.h>

t_map_node *tmap_set(t_map *map, char *key, void *value)
{
    t_map_node *node;
    if ((node = tmap_get(map, key)) == NULL)
        return NULL;
    node->value = value;
    return node;
}
