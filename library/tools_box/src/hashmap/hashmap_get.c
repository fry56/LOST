/*
** EPITECH PROJECT, 2023
** hashmap_get.c
** File description:
** desc
*/

#include <t_hashmap.h>
#include <t_string.h>

t_hashmap_node *thashmap_get(t_hashmap *hashmap, const char *key)
{
    uint32_t hash;

    if (hashmap == NULL || tstr_len(key) == 0)
        return NULL;
    hash = hashmap_get_hash(hashmap->size, key);
    if (hashmap->map[hash] == NULL)
        return NULL;
    if (tstr_cmp(key, hashmap->map[hash]->key) == 0)
        return hashmap->map[hash];
    list_foreach(hashmap->map[hash]->childs_node, node) {
        if (tstr_cmp(key, ((t_hashmap_node *)node->value)->key) == 0)
            return node->value;
    }
    return NULL;
}
