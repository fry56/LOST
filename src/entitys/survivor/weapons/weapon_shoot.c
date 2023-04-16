/*
** EPITECH PROJECT, 2023
** weapon_shoot.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <survivor/survivor.h>
#include <survivor/weapon/weapon_config.h>
#include <raycast.h>
#include <zombie/zombie.h>

static void raycast_bullet(sprite *sprite_datas)
{
    survivor_s *survivor_datas = sprite_datas->datas;
    sprite *target = raycast_nearest_sprite_by_flag(sprite_datas,
        weapons_config[survivor_datas->weapon_mgr->equiped_weapon].shoot_range,
        "target");

    if (target != NULL)
        zombie_damage(target, weapons_config[survivor_datas->weapon_mgr->
            equiped_weapon].shoot_damage);
}

void weapon_shoot(sprite *sprite_datas, sfUint64 timestamp)
{
    survivor_s *survivor_datas = sprite_datas->datas;
    weapons_type_e equiped = survivor_datas->weapon_mgr->equiped_weapon;
    weapon_s *weapon = &survivor_datas->weapon_mgr->weapons[equiped];

    if (timestamp < weapon->shoot +
        (sfUint64)(weapons_config[weapon->type].fire_rate * 100000))
        return;
    if (weapon->loaded_ammos <= 0) {
        sound_manager_play_sound(survivor_datas->sound_mgr,
            weapons_config[equiped].sound_empty);
        weapon->shoot = timestamp;
        return;
    }
    weapon->loaded_ammos--;
    animator_play_animation(sprite_datas->animator,
        get_survivor_anim_by_type(survivor_datas, anim_shoot).name);
    sound_manager_play_sound(survivor_datas->sound_mgr,
        weapons_config[equiped].sound_shoot);
    raycast_bullet(sprite_datas);
    weapon->shoot = timestamp;
}
