/*
** EPITECH PROJECT, 2023
** move_survivor.c
** File description:
** desc
*/

#include "Class/t_sprite.h"
#include "Class/t_sound_manager.h"
#include "survivor/survivor.h"
#include <map/map.h>
#include <t_assert.h>
#include <utils.h>
#include <zombie/zombie.h>

static void update_zombie_path(sprite *sprite_datas, survivor_s *survivor_datas)
{
    sprite *temp_sprite;
    zombie_s *temp_zombie;

    list_foreach(sprite_datas->host->list_sprites, node) {
        temp_sprite = node->value;
        if (!sprite_have_flag(temp_sprite, "zombie"))
            continue;
        temp_zombie = temp_sprite->datas;
        if (temp_zombie->status != trigger)
            continue;
        temp_zombie->pathfinding_mgr->target = survivor_datas->pathfinding_node;
        pathfinding_update_entity(temp_zombie->pathfinding_mgr);
    }
}

void survivor_move(sprite *sprite_datas, sfVector2f pos UNUSED)
{
    survivor_s *survivor_datas = sprite_datas->datas;

    sfListener_setPosition((sfVector3f){sprite_datas->pos.x,
        sprite_datas->pos.y, 0});
    sound_manager_set_pos(survivor_datas->sound_mgr, sprite_datas->pos);
    survivor_event_mouse_move(sprite_datas, sprite_datas->host->host);
    sfView_setCenter(sprite_datas->host->view,
        (sfVector2f){sprite_datas->pos.x, sprite_datas->pos.y});
    tassert(survivor_datas->box_collider == NULL);
    box_collider_set_pos(survivor_datas->box_collider, sprite_datas->pos);
    survivor_datas->pathfinding_node = get_pathfinding_node_by_pos(
        ((map_s *)sprite_datas->host->datas)->pathfinding_mgr, pos);
    sprite *box_collider = sprite_get_by_flag(sprite_datas->host, "box_collider");
    sprite_set_pos(box_collider, sprite_datas->pos);
    update_zombie_path(sprite_datas, survivor_datas);
}
