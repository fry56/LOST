/*
** EPITECH PROJECT, 2023
** zombie_init_pathfinding.c
** File description:
** desc
*/

#include <zombie/zombie.h>
#include <t_mem.h>
#include <map/map.h>
#include <utils.h>

static void alloc_local_node(pathfinding_manager_s *mgr,
    pathfinding_entity_s *entity_mgr)
{
    for (uint32_t i = 0; i < mgr->size.x * mgr->size.y; ++i) {
        entity_mgr->nodes[i] = tcalloc(1, sizeof(pathfinding_entity_node_s));
        entity_mgr->nodes[i]->id = i;
        entity_mgr->nodes[i]->node = mgr->nodes[i];
        entity_mgr->nodes[i]->g = 0;
        entity_mgr->nodes[i]->h = 0;
    }
}

void zombie_init_pathfinding(zombie_s *zombie_datas)
{
    pathfinding_manager_s *mgr =
        ((map_s *)zombie_datas->host->host->datas)->pathfinding_mgr;
    pathfinding_entity_s *entity_mgr;

    zombie_datas->pathfinding_mgr = tcalloc(1, sizeof(pathfinding_entity_s));
    entity_mgr = zombie_datas->pathfinding_mgr;
    entity_mgr->nodes = tcalloc(mgr->size.x * mgr->size.y,
        sizeof(pathfinding_entity_node_s *));
    entity_mgr->current = get_pathfinding_node_by_pos(mgr,
        zombie_datas->host->pos);
    entity_mgr->list_close = tlist_new();
    entity_mgr->list_open = tlist_new();
    entity_mgr->list_path = tlist_new();
    entity_mgr->host = zombie_datas->host;
    alloc_local_node(mgr, entity_mgr);
}
