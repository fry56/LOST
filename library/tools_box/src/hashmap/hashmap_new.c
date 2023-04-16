/*
** EPITECH PROJECT, 2023
** hashmap_new.c
** File description:
** desc
*/

#include <t_hashmap.h>
#include <t_mem.h>
#include <t_assert.h>

t_hashmap *thashmap_new(u32 size)
{
    t_hashmap *new_hashmap = tcalloc(1, sizeof(t_hashmap));

    tassert(new_hashmap == NULL && "New Hashmap == NULL");
    size = size + (int)(size * 0.75);
    new_hashmap->size = size;
    new_hashmap->node_elements = 0;
    new_hashmap->child_elements = 0;
    tassert((new_hashmap->map = tcalloc(size, sizeof(t_hashmap_node *))) == NULL
        && "New hashmap node == NULL");
    return new_hashmap;
}
