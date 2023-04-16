/*
** EPITECH PROJECT, 2023
** get_pathfinding_node_by_pos.c
** File description:
** desc
*/

#include <pathfinding/pathfinding.h>

pathfinding_node_s *get_pathfinding_node_by_pos(pathfinding_manager_s *mgr,
    sfVector2f pos)
{
    sfVector2f new_pos = {pos.x + ((int)(64 - pos.x) % 64),
        pos.y + ((int)(64 - pos.y) % 64)};
    return mgr->nodes[(int)(((new_pos.y / 64) * mgr->width) + new_pos.x / 64)];
}
