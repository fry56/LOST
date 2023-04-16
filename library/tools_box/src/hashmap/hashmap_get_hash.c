/*
** EPITECH PROJECT, 2023
** hashmap_get_hash.c
** File description:
** desc
*/

#include <t_hashmap.h>
#include <t_ctype.h>

u32 hashmap_get_hash(u32 size, const char *key)
{
    uint64_t hash;

    for (hash = 0; *key; key++)
        hash = *key + (hash << 6) + (hash << 16) - hash;
    return hash % size;
}
