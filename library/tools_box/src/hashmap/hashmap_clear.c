/*
** EPITECH PROJECT, 2023
** hashmap_clear.c
** File description:
** desc
*/

#include <t_hashmap.h>
#include <stdlib.h>

void thashmap_clear(t_hashmap *hashmap)
{
    if (hashmap == NULL)
        return;
    for (u32 i = 0; i < hashmap->size; ++i) {
        if (hashmap->map[i]) {
            tlist_clear(hashmap->map[i]->childs_node);
            free(hashmap->map[i]);
        }
    }
}
