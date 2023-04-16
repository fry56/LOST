/*
** EPITECH PROJECT, 2023
** hashmap_foreach.c
** File description:
** desc
*/

#include <t_hashmap.h>

static void for_child(t_hashmap_node *hashmap_node
    , void (function)(char *key, void *value))
{
    if (hashmap_node->childs_node != NULL) {
        list_foreach(hashmap_node->childs_node, node)
            function(hashmap_node->key, node->value);
    }
}

void thashmap_foreach(t_hashmap *hashmap
    , void (function)(char *key, void *value))
{
    if (hashmap == NULL)
        return;
    for (u32 i = 0; i < hashmap->size; ++i) {
        if (hashmap->map[i] != NULL) {
            function(hashmap->map[i]->key, hashmap->map[i]->value);
            for_child(hashmap->map[i], function);
        }
    }
}
