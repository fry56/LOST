/*
** EPITECH PROJECT, 2023
** movement.c
** File description:
** desc
*/

#include "Class/t_sprite.h"
#include "Class/t_sound_manager.h"
#include "survivor/survivor.h"
#include "utils.h"
#include <t_string.h>

static survivor_movement_s *find_movement_by_key(sfKeyCode key)
{
    for (int i = 0; survivor_movements_config[i].key != sfKeyUnknown; ++i) {
        if (survivor_movements_config[i].key == key)
            return &survivor_movements_config[i];
    }
    return NULL;
}

static survivor_movement_s *get_survivor_movement(scene *scene_datas)
{
    survivor_movement_s *movement;

    list_foreach(scene_datas->list_keys, node) {
        if (!((key_bind *)node->value)->is_press)
            continue;
        if ((movement = find_movement_by_key(((key_bind *)node->value)->key)) !=
            NULL)
            return movement;
    }
    return NULL;
}

static bool is_moving(sprite *sprite_datas, survivor_movement_s *movement,
    survivor_s *survivor_datas)
{
    if (movement == NULL || get_distance(sprite_datas->pos,
        survivor_datas->mouse_pos) < 10) {
        if (survivor_datas->actual_movement != sfKeyUnknown) {
            sound_manager_stop_sound(survivor_datas->sound_mgr,
                "sound_survivor_footstep");
            animator_play_animation(sprite_datas->animator,
                get_survivor_anim_by_type(survivor_datas, anim_idle).name);
        }
        survivor_datas->actual_movement = sfKeyUnknown;
        return false;
    }
    return true;
}

static void survivor_play_mov_anim(sprite *sprite_datas,
    survivor_movement_s *movement)
{
    survivor_s *survivor_datas = sprite_datas->datas;
    char *anim_name = get_survivor_anim_by_type(survivor_datas, anim_idle).name;

    if (((survivor_s *)sprite_datas->datas)->actual_movement != movement->key) {
        animator_play_animation(sprite_datas->animator,
            movement->animation_name);
        sfSprite_setScale(sprite_datas->sf_sprite,
            (sfVector2f){movement->scale.x, movement->scale.y});
        ((survivor_s *)sprite_datas->datas)->actual_movement = movement->key;
    }
    sound_manager_play_sound(survivor_datas->sound_mgr,
        "sound_survivor_footstep");
    if (!tstr_cmp(anim_name,
        ((animation *)sprite_datas->animator->played_animation->value)->name))
        animator_play_animation(sprite_datas->animator,
            get_survivor_anim_by_type(survivor_datas, anim_move).name);
}

void survivor_event_movements(sprite *sprite_datas, sfClock *clock UNUSED)
{
    scene *scene_datas = sprite_datas->host;
    survivor_movement_s *movement = get_survivor_movement(scene_datas);
    survivor_s *survivor_datas = sprite_datas->datas;
    sfVector2f new_pos = get_angle_offset(sprite_datas->pos,
        get_relative_mouse_pos(survivor_datas));

    if (!is_moving(sprite_datas, movement, survivor_datas) ||
        survivor_datas->freeze)
        return;
    new_pos = (sfVector2f){
        new_pos.x * (survivor_datas->speed + survivor_datas->speed_level)
            * scene_datas->host->deltatime * movement->offset.x,new_pos.y *
        (survivor_datas->speed + survivor_datas->speed_level)
        * scene_datas->host->deltatime * movement->offset.y};
    new_pos = get_valide_offset(survivor_datas->temp_datas->box_collider,
        new_pos);
    sprite_move(sprite_datas, new_pos);
    survivor_play_mov_anim(sprite_datas, movement);
}
