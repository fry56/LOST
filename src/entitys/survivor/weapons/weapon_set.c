/*
** EPITECH PROJECT, 2023
** weapon_set.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <Class/t_window.h>
#include <survivor/weapon/weapon.h>
#include <survivor/weapon/weapon_config.h>
#include <survivor/survivor.h>

void weapon_set(sprite *sprite_datas, weapons_type_e type)
{
    survivor_s *survivor_datas = sprite_datas->datas;
    weapons_manager_s *weapon_mgr = survivor_datas->weapon_mgr;
    char *anim_name;
    window *window_datas = sprite_datas->host->host;
    sfUint64 timestamp =
            sfClock_getElapsedTime(window_datas->global_clock).microseconds;

    weapon_mgr->equiped_weapon = type;
    anim_name = get_survivor_anim_by_type(survivor_datas, anim_idle).name;
    animator_play_animation(sprite_datas->animator, anim_name);
    sprite_datas->animator->default_animation =
        thashmap_get(window_datas->map_datas, anim_name);
    sound_manager_play_sound(survivor_datas->sound_mgr, "sound_survivor_equip");
    weapon_mgr->timestamp_weapon_change = timestamp;
}
