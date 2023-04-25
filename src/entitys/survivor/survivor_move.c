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
#include <utils.h>
#include <zombie/zombie.h>

void update_zombie_path(sprite *sprite_datas, survivor_s *survivor_datas)
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
        temp_zombie->pathfinding_mgr->target =
            survivor_datas->temp_datas->pathfinding_node;
        pathfinding_update_entity(temp_zombie->pathfinding_mgr);
    }
}

static void trigger_nearest_zombie(sprite *sprite_datas)
{
    zombie_s *temp_zombie;

    list_foreach(sprite_datas->host->list_sprites, node) {
        if (!sprite_have_flag(node->value, "zombie"))
            continue;
        temp_zombie = ((sprite *)node->value)->datas;
        if (temp_zombie->status != idle)
            continue;
        if (get_distance(sprite_datas->pos, ((sprite *)node->value)->pos) < 350)
            zombie_set_trigger(node->value);
    }
}

void view_manager(sprite *sprite_datas)
{
    map_s *map_datas = sprite_datas->host->datas;
    sfVector2u size = sfRenderWindow_getSize(sprite_datas->host->host->window);
    sfVector2f new_offset = sprite_datas->pos;
    sfVector2f move_offset = sfView_getCenter(sprite_datas->host->view);

    if (new_offset.x < size.x / 2)
        new_offset.x = size.x / 2;
    if (new_offset.x > (map_datas->width * map_datas->t_width) - size.x / 2)
        new_offset.x = (map_datas->width * map_datas->t_width) - size.x / 2;
    if (new_offset.y < size.y / 2)
        new_offset.y = size.y / 2;
    if (new_offset.y > (map_datas->height * map_datas->t_height) - size.y / 2)
        new_offset.y = (map_datas->height * map_datas->t_height) - size.y / 2;
    sfView_setCenter(sprite_datas->host->view, new_offset);
    canva_update(sprite_datas->host, (sfVector2f){
        -(move_offset.x - new_offset.x), -(move_offset.y - new_offset.y)});
}

void survivor_move(sprite *sprite_datas, sfVector2f pos UNUSED)
{
    survivor_s *survivor_datas = sprite_datas->datas;

    sfListener_setPosition((sfVector3f){sprite_datas->pos.x,
        sprite_datas->pos.y, 0});
    sound_manager_set_pos(survivor_datas->sound_mgr, sprite_datas->pos);
    survivor_event_mouse_move(sprite_datas, sprite_datas->host->host);
    view_manager(sprite_datas);
    box_collider_set_pos(survivor_datas->temp_datas->box_collider,
        sprite_datas->pos);
    survivor_datas->temp_datas->pathfinding_node = get_pathfinding_node_by_pos(
        ((map_s *)sprite_datas->host->datas)->pathfinding_mgr,
        sprite_datas->pos);
    trigger_nearest_zombie(sprite_datas);
    update_zombie_path(sprite_datas, survivor_datas);
}
