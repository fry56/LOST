/*
** EPITECH PROJECT, 2022
** map_get.c
** File description:
** desc
*/

#include <t_ctype.h>
#include <t_map.h>
#include <t_string.h>

t_map_node *tmap_get(t_map *map, char *key)
{
    if (map == NULL)
        return NULL;
    map_foreach(map, node) {
        if (tstr_cmp(node->key, key) == 0)
            return node;
    }
    return NULL;
}
