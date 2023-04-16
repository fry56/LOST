/*
** EPITECH PROJECT, 2023
** hashmap_free.c
** File description:
** desc
*/

#include <t_hashmap.h>
#include <stdlib.h>

void thashmap_free(t_hashmap *hashmap)
{
    if (hashmap == NULL)
        return;
    thashmap_clear(hashmap);
    free(hashmap);
}
