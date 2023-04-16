/*
** EPITECH PROJECT, 2023
** zombie_init.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <t_mem.h>
#include <t_assert.h>
#include <zombie/zombie.h>
#include <box_collider/box_collider.h>
#include <map/map.h>

void zombie_set_datas(sprite *new_zombie, zombie_s *zombie_datas)
{
    zombie_datas->host = new_zombie;
    zombie_datas->timestamp_interaction = 0;
    zombie_datas->health = 50 + (rand() % 50);
    zombie_datas->status = idle;
    new_zombie->set_pos = zombie_set_pos;
    new_zombie->move = zombie_move;
    new_zombie->destroy = zombie_destroy;
}

sprite *zombie_init(scene *scene_datas, sfVector2f pos)
{
    sprite *new_zombie = new_sprite(scene_datas, NULL, 20);
    zombie_s *zombie_datas = tcalloc(1, sizeof(zombie_s));

    tassert(zombie_datas == NULL);
    new_zombie->datas = zombie_datas;
    sprite_add_flag(new_zombie, "target");
    sprite_add_flag(new_zombie, "zombie");
    zombie_init_animations(scene_datas, new_zombie);
    sprite_set_fixed_origin(new_zombie, (sfVector2f){258, 327});
    sprite_set_pos(new_zombie, pos);
    sfSprite_setScale(new_zombie->sf_sprite, (sfVector2f){0.6f, 0.6f});
    zombie_datas->sound_mgr = new_sound_manager(scene_datas, pos, 250, 100);
    zombie_datas->box_collider = new_box_collider(((map_s *)new_zombie->host->datas)->box_colliders_mgr,
        (sfIntRect){pos.x, pos.y, 50, 50}, true);
    zombie_set_datas(new_zombie, zombie_datas);
    zombie_init_sound_mgr(scene_datas, new_zombie);
    zombie_init_pathfinding(zombie_datas);
    sprite_add_clock_update_function(new_zombie, zombie_event_move);
    return new_zombie;
}
