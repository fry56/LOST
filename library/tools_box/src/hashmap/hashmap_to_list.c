/*
** EPITECH PROJECT, 2023
** hashmap_to_list.c
** File description:
** desc
*/

#include <t_list.h>
#include <t_hashmap.h>

static void add_child(t_hashmap_node *hashmap_node, t_list *new_list)
{
    if (hashmap_node->childs_node) {
        list_foreach(hashmap_node->childs_node, node)
            tlist_add(new_list, ((t_hashmap_node *)node->value)->value);
    }
}

t_list *thashmap_to_list(t_hashmap *hashmap)
{
    t_list *new_list;

    if (hashmap == NULL || (new_list = tlist_new()) == NULL)
        return NULL;
    for (u32 i = 0; i < hashmap->size; ++i) {
        if (hashmap->map[i]) {
            tlist_add(new_list, hashmap->map[i]->value);
            add_child(hashmap->map[i], new_list);
        }
    }
    return new_list;
}
