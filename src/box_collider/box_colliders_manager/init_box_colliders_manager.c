/*
** EPITECH PROJECT, 2023
** new_collision_manager.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <map/map.h>
#include <t_mem.h>
#include <Class/t_text.h>
#include <t_string.h>

void init_box_coliders_manager(map_s *map_datas)
{
    box_colliders_manager_s *mgr = tcalloc(1, sizeof(box_colliders_manager_s));
    sfVector2u size;

    map_datas->box_colliders_mgr = mgr;
    mgr->host = map_datas;
    mgr->width = map_datas->width + ((map_datas->width % 256) > 0 ? 1 : 0);
    mgr->height = map_datas->height + ((map_datas->width % 256) > 0 ? 1 : 0);
    size = (sfVector2u){(mgr->width * map_datas->t_width) / 256,
            (mgr->height * map_datas->t_height) / 256};
    mgr->list_zones = tcalloc(size.x * size.y, sizeof(t_list *));
    for (uint32_t i = 0; i < size.x * size.y; ++i)
        mgr->list_zones[i] = tlist_new();
}
