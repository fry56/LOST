/*
** EPITECH PROJECT, 2023
** init_pathfinding_manager.c
** File description:
** desc
*/

#include <pathfinding/pathfinding.h>
#include <t_mem.h>
#include <map/map.h>
#include <t_list.h>
#include <box_collider/box_collider.h>

void add_parent_node(pathfinding_manager_s *mgr, pathfinding_node_s *node,
    uint32_t index)
{
    int temp_index = index - mgr->size.x - 1;
    int temp_line = (temp_index / (int)mgr->size.y);
    int default_index = index % (int)mgr->size.x;
    for (int i = 0; i < 8; ++i, temp_index++) {
        if (i == 3 || i == 6) {
            temp_index += (mgr->size.x - 3);
            temp_line++;
        }
        if (temp_index < 0 || temp_index > (int)(mgr->size.x * mgr->size.y) ||
            (int)index == temp_index || temp_line < 0)
            continue;
        if (default_index == 0 && (i == 0 || i == 3 || i == 6 ||
            temp_index % (int)mgr->size.x > default_index + 2))
            continue;
        if (default_index == (int)mgr->size.x - 1 &&
            (i == 2 || i == 5 || i == 7))
            continue;
        node->child_node[node->nbr_child++] = mgr->nodes[temp_index];
    }
}

static void setup_parent_node(pathfinding_manager_s *mgr)
{
    for (uint32_t i = 0; i < (mgr->size.x * mgr->size.y); ++i)
        if (!mgr->nodes[i]->is_blocking)
            add_parent_node(mgr, mgr->nodes[i], i);
}

static void create_node(map_s *map_datas)
{
    sfVector2f temp_pos;
    t_list *temp_zone;
    pathfinding_manager_s *mgr = map_datas->pathfinding_mgr;
    pathfinding_node_s *temp_node;
    for (uint32_t i = 0; i < (mgr->size.x * mgr->size.y); ++i) {
        temp_pos = (sfVector2f){(i % mgr->size.x) * 64, (i / mgr->size.y) * 64};
        temp_zone = get_zone_by_pos(map_datas->box_colliders_mgr, temp_pos);
        if (temp_zone == NULL)
            continue;
        temp_node = tcalloc(1, sizeof(pathfinding_node_s));
        mgr->nodes[i] = temp_node;
        temp_node->pos = temp_pos;
        temp_node->id = i;
        temp_node->list_zone = temp_zone;
        temp_node->nbr_child = 0;
        if ((temp_node->is_blocking = is_collide(temp_zone, (sfIntRect)
            {temp_pos.x, temp_pos.y, 50, 50})) == true)
            continue;
    }
    setup_parent_node(mgr);
}

void init_pathfinding_manager(map_s *map_datas)
{
    pathfinding_manager_s *mgr = tcalloc(1, sizeof(pathfinding_manager_s));

    map_datas->pathfinding_mgr = mgr;
    mgr->host = map_datas;
    mgr->width = map_datas->width + ((map_datas->width % 64) > 0 ? 1 : 0);
    mgr->height = map_datas->height + ((map_datas->width % 64) > 0 ? 1 : 0);
    mgr->size = (sfVector2u){(mgr->width * map_datas->t_width) / 64,
        (mgr->height * map_datas->t_height) / 64};
    mgr->nodes =
        tcalloc(mgr->size.x * mgr->size.y, sizeof(pathfinding_node_s *));
    create_node(map_datas);
}
