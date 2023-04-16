/*
** EPITECH PROJECT, 2023
** zombie_event_move.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <zombie/zombie.h>
#include <utils.h>

void zombie_event_move(sprite *sprite_datas, sfClock *clock UNUSED)
{
    zombie_s *zombie_datas = sprite_datas->datas;
    pathfinding_entity_s *mgr = zombie_datas->pathfinding_mgr;
    pathfinding_node_s *path_node;
    t_list_node *node;
    scene *scene_datas = sprite_datas->host;
    sfVector2f new_pos;

    if (zombie_datas->status != trigger || mgr->list_path->length == 0)
        return;
    node = tlist_get(zombie_datas->pathfinding_mgr->list_path, 1);
    if (node == NULL)
        return;
    path_node = node->value;
    sfSprite_setRotation(zombie_datas->host->sf_sprite,
        get_angle_from_coordinate(zombie_datas->host->pos, path_node->pos));
    new_pos = get_angle_offset(sprite_datas->pos, path_node->pos);
    new_pos = (sfVector2f){ new_pos.x * 3 * scene_datas->host->deltatime * 1,
            new_pos.y * 3 * scene_datas->host->deltatime * 1};
    new_pos = get_valide_offset(zombie_datas->box_collider, new_pos);
    sprite_move(sprite_datas, new_pos);
    if (get_distance(sprite_datas->pos, path_node->pos) < 10) {
        tlist_remove(zombie_datas->pathfinding_mgr->list_path, node);
        zombie_datas->pathfinding_mgr->current = path_node;
    }
}
