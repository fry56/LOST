/*
** EPITECH PROJECT, 2023
** get_tileset.c
** File description:
** desc
*/

#include <map/map.h>
#include <t_string.h>
#include <utils.h>

map_tileset_index_s *get_tileset(map_s *map_datas, long id)
{
    map_tileset_index_s *temp;

    id = id & ~(FLIPPED_HORIZONTALLY_FLAG |
                FLIPPED_VERTICALLY_FLAG | FLIPPED_DIAGONALLY_FLAG);
    list_foreach(map_datas->list_tileset, node) {
        temp = node->value;
        if (temp->end_index < id && temp->end_index != -1)
            continue;
        return temp;
    }
    return NULL;
}
