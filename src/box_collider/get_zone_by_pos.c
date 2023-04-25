/*
** EPITECH PROJECT, 2023
** get_zone_by_pos.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <map/map.h>
#include <math.h>

t_list *get_zone_by_pos(box_colliders_manager_s *mgr, sfVector2f pos)
{
    map_s *map_datas = mgr->host;
    sfVector2i max_pos = {map_datas->t_width * map_datas->width,
        map_datas->t_height * map_datas->height};
    pos = (sfVector2f){pos.x == (float)max_pos.x ? pos.x - 64 : pos.x,
        pos.y == (float)max_pos.y ? pos.y - 64 : pos.y};
    sfVector2i index = {(int32_t)pos.x / 256, (int32_t)pos.y / 256};
    int array_index;

    if ((int)pos.x > max_pos.x || (int)pos.y > max_pos.y ||
        pos.x < 0 || pos.y < 0)
        return NULL;
    array_index = (int)(index.y * ceil((mgr->width * map_datas->t_width) / 256)
        + index.x);
    if (array_index > ((max_pos.x / 256) * ((max_pos.y / 256) + 64)))
        return NULL;
    return mgr->list_zones[array_index];
}
