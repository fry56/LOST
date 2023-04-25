/*
** EPITECH PROJECT, 2023
** survivor_change_map.c
** File description:
** desc
*/

#include <survivor/survivor.h>

void survivor_update_map(sprite *sprite_datas)
{
    survivor_s *survivor_datas = sprite_datas->datas;
    t_hashmap_node *scene = thashmap_get(sprite_datas->host->host->map_datas,
        "current_game_scene");

    survivor_datas->temp_datas =
        thashmap_get(sprite_datas->host->map_datas, "SURVIVOR_TEMP")->value;
    weapon_set(sprite_datas, survivor_datas->weapon_mgr->equiped_weapon);
    view_manager(sprite_datas);
    scene->value = sprite_datas->host->scene_node->key;
}
