/*
** EPITECH PROJECT, 2023
** pathfinding_update_entity.c
** File description:
** desc
*/

#include <pathfinding/pathfinding.h>
#include <stdio.h>
#include <math.h>
#include <map/map.h>

static bool is_side_move(sfVector2f pos_a, sfVector2f pos_b)
{
    sfVector2u condition = {
        pos_b.x - 64 == pos_a.x || pos_b.x + 64 == pos_a.x,
        pos_b.y - 64 == pos_a.y || pos_b.y + 64 == pos_a.y
    };
    return condition.x && condition.y;
}

static void add_child_to_open_list(pathfinding_entity_s *entity,
    pathfinding_node_s *node)
{
    register pathfinding_entity_node_s *temp_node;

    for (int i = 0; i < node->nbr_child; i++) {
        temp_node = entity->nodes[node->child_node[i]->id];
        if (tlist_find(entity->list_open, temp_node) ||
            temp_node->node->is_blocking)
            continue;
        tlist_add(entity->list_open, entity->nodes[temp_node->id]);
        temp_node->parent_node = entity->nodes[node->id];
        temp_node->g = entity->nodes[node->id]->g + (is_side_move(entity->nodes
            [node->id]->node->pos, temp_node->node->pos) ? 14 : 10);
        temp_node->h = fabsf(entity->target->pos.x - temp_node->node->pos.x) +
            fabsf(entity->target->pos.y - temp_node->node->pos.y);
        temp_node->f = temp_node->g + temp_node->h;
    }
}

static pathfinding_entity_node_s *get_lowest_f_cost(
    pathfinding_entity_s *entity)
{
    uint32_t lowest_value = 999999;
    pathfinding_entity_node_s *lowest = NULL;
    t_list_node *temp;

    list_foreach(entity->list_open, node) {
        if (((pathfinding_entity_node_s *)node->value)->f < lowest_value) {
            lowest = node->value;
            lowest_value = ((pathfinding_entity_node_s *)node->value)->f;
            temp = node;
        }
    }
    tlist_remove(entity->list_open, temp);
    return lowest;
}

void pathfinding_update_entity(pathfinding_entity_s *entity)
{
    pathfinding_entity_node_s *current;

    tlist_clear(entity->list_open);
    tlist_clear(entity->list_close);
    tlist_clear(entity->list_path);
    tlist_add(entity->list_open, entity->nodes[entity->current->id]);
    entity->nodes[entity->current->id]->parent_node = NULL;
    for (int i = 0; i < 400; ++i) {
        current = get_lowest_f_cost(entity);
        tlist_add(entity->list_close, current);
        tlist_add(entity->list_path, current->node);
        if (current == entity->nodes[entity->target->id])
            break;
        add_child_to_open_list(entity, current->node);
        if (entity->list_open->length == 0) {
            tlist_clear(entity->list_path);
            break;
        }
    }
}
