/*
** EPITECH PROJECT, 2023
** zombie_event_move.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <zombie/zombie.h>
#include <utils.h>
#include <t_string.h>
#include <stdlib.h>
#include <map/map.h>

static void zombie_move_pathfinding(sprite *sprite_datas,
    zombie_s *zombie_datas,t_list_node *node, pathfinding_node_s *path_node)
{
    scene *scene_datas = sprite_datas->host;
    sfVector2f new_pos = get_angle_offset(sprite_datas->pos, path_node->pos);

    new_pos = (sfVector2f){new_pos.x * 3 * scene_datas->host->deltatime * 1,
        new_pos.y * 3 * scene_datas->host->deltatime * 1};
    new_pos = get_valide_offset(zombie_datas->box_collider, new_pos);
    sprite_move(sprite_datas, new_pos);
    if (get_distance(sprite_datas->pos, path_node->pos) < 10) {
        tlist_remove(zombie_datas->pathfinding_mgr->list_path, node);
        zombie_datas->pathfinding_mgr->current = path_node;
    }
}

static void zombie_near_of_survivor(sprite *sprite_datas)
{
    sprite *survivor_sprite =
        ((map_s *)sprite_datas->host->datas)->survivor_entity;
    char *anim_name = get_zombie_anim_by_type(sprite_datas->datas,
        anim_melee).name;

    if (!tstr_cmp(anim_name,
        ((animation *)sprite_datas->animator->played_animation->value)->name))
        return;
    if (get_distance(sprite_datas->pos, survivor_sprite->pos) < 100)
        zombie_event_attack(sprite_datas);
}

void zombie_event_move(sprite *sprite_datas, sfClock *clock UNUSED)
{
    zombie_s *zombie_datas = sprite_datas->datas;
    pathfinding_entity_s *mgr = zombie_datas->pathfinding_mgr;
    pathfinding_node_s *path_node;
    t_list_node *node;
    char *anim_name = get_zombie_anim_by_type(zombie_datas, anim_idle).name;
    if (zombie_datas->status != trigger || mgr->list_path->length == 0)
        return;
    if ((node = tlist_get(zombie_datas->pathfinding_mgr->list_path, 1)) == NULL)
        return;
    path_node = node->value;
    sfSprite_setRotation(zombie_datas->host->sf_sprite,
        get_angle_from_coordinate(zombie_datas->host->pos, path_node->pos));
    zombie_move_pathfinding(sprite_datas, zombie_datas, node, path_node);
    zombie_near_of_survivor(sprite_datas);
    if (!tstr_cmp(anim_name, ((animation *)sprite_datas->animator->
        played_animation->value)->name)) {
        animator_play_animation(sprite_datas->animator,
            get_zombie_anim_by_type(zombie_datas, anim_move).name);
        animator_set_random_frame(sprite_datas->animator);
    }
}
