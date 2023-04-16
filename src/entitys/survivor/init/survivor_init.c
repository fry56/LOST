/*
** EPITECH PROJECT, 2023
** init_player.c
** File description:
** desc
*/

#include "Class/t_sprite.h"
#include "survivor/survivor.h"
#include "entity_animations.h"
#include <map/map.h>
#include <utils.h>

static void set_survivor_datas(sprite *new_survivor,
    survivor_s *survivor_datas)
{
    survivor_datas->mouse_pos = (sfVector2f){0, 0};
    survivor_datas->freeze = false;
    new_survivor->destroy = survivor_destroy;
    new_survivor->move = survivor_move;
    new_survivor->set_pos = survivor_set_pos;
}

static void set_survivor_event(sprite *new_survivor)
{
    sprite_add_event_update_function(new_survivor, survivor_event_mouse_move);
    sprite_add_event_update_function(new_survivor, survivor_event_mouse_click);
    sprite_add_event_update_function(new_survivor, survivor_event_space);
    sprite_add_event_update_function(new_survivor,
        survivor_event_weapon_reload);
    sprite_add_event_update_function(new_survivor, weapon_change);
    sprite_add_clock_update_function(new_survivor, survivor_event_movements);
    sprite_add_event_update_function(new_survivor, survivor_event_interactions);
}

sprite *survivor_init(scene *scene_datas, sfVector2f pos)
{
    sprite *new_survivor = new_sprite(scene_datas, NULL, 21);
    survivor_s *survivor_datas = thashmap_get(
        ((window *)scene_datas->host)->map_datas, "SURVIVOR_DATAS")->value;
    survivor_datas->host = new_survivor;
    new_survivor->datas = survivor_datas;
    survivor_datas->box_collider = new_box_collider(((map_s *)new_survivor->host->datas)->box_colliders_mgr,
         (sfIntRect){pos.x, pos.y, 25, 25}, true);
    survivor_datas->box_collider->host = new_survivor;
    survivor_init_animations(scene_datas, new_survivor);
    sprite_set_fixed_origin(new_survivor, (sfVector2f){105.0f, 112.0f});
    sfSprite_setScale(new_survivor->sf_sprite, (sfVector2f){0.5f, 0.5f});
    survivor_datas->sound_mgr = new_sound_manager(scene_datas, pos, 250, 100);
    survivor_init_sound_mgr(scene_datas, new_survivor);
    set_survivor_datas(new_survivor, survivor_datas);
    set_survivor_event(new_survivor);
    sprite_set_pos(new_survivor, pos);
    ((map_s *)new_survivor->host->datas)->survivor_entity = new_survivor;
    survivor_datas->pathfinding_node = get_pathfinding_node_by_pos(
        ((map_s *)new_survivor->host->datas)->pathfinding_mgr, pos);
    sprite *box_collider = new_sprite(scene_datas, "assets/map/box_collider.png", 5);
    sprite_add_flag(box_collider, "box_collider");
    sprite_set_pos(box_collider, pos);
    return new_survivor;
}
