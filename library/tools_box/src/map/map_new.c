/*
** EPITECH PROJECT, 2022
** map_new.c
** File description:
** desc
*/

#include <t_map.h>
#include <t_assert.h>
#include <t_mem.h>

t_map *tmap_new(void)
{
    t_map *new_map = tcalloc(1, sizeof(t_map));

    tassert(new_map == NULL);
    return new_map;
}
