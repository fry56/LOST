/*
** EPITECH PROJECT, 2023
** hashmap_add.c
** File description:
** desc
*/

#include <t_hashmap.h>
#include <stdlib.h>
#include <t_string.h>
#include <t_mem.h>
#include <t_assert.h>

bool insert_node_to_hashmap(t_hashmap *hashmap, t_hashmap_node *new_node)
{
    new_node->hash = hashmap_get_hash(hashmap->size, new_node->key);
    if (thashmap_get(hashmap, new_node->key) != NULL)
        return false;
    new_node->hash = new_node->hash;
    if (!hashmap->map[new_node->hash]) {
        hashmap->map[new_node->hash] = new_node;
        hashmap->node_elements++;
        new_node->parent_node = NULL;
        new_node->childs_node = tlist_new();
    } else {
        new_node->parent_node = hashmap->map[new_node->hash];
        new_node->childs_node = NULL;
        tlist_add(hashmap->map[new_node->hash]->childs_node, new_node);
        hashmap->child_elements++;
    }
    return true;
}

t_hashmap_node *thashmap_add(t_hashmap *hashmap, char *key, void *value)
{
    t_hashmap_node *new_node;

    if (hashmap == NULL || tstr_len(key) == 0 || value == NULL)
        return NULL;
    tassert((new_node = tcalloc(1, sizeof(t_hashmap_node))) == NULL);
    new_node->host = hashmap;
    new_node->key = key;
    new_node->value = value;
    if (!insert_node_to_hashmap(hashmap, new_node)) {
        free(new_node);
        return NULL;
    }
    return new_node;
}
