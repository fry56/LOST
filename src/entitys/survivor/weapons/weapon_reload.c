/*
** EPITECH PROJECT, 2023
** reload_weapon.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <survivor/survivor.h>
#include <survivor/weapon/weapon_config.h>

static void reload_methode(weapon_s *weapon, weapons_type_e equiped,
    sprite *sprite_datas, uint64_t timestamp)
{
survivor_s *survivor_datas = sprite_datas->datas;

    if (weapon->ammos <= 0)
        return;
    if (weapon->ammos < weapons_config[equiped].magazin_size) {
        weapon->loaded_ammos = weapon->ammos;
        weapon->ammos = 0;
    } else {
        if (weapon->loaded_ammos > 0)
            weapon->ammos += weapon->loaded_ammos;
        weapon->ammos -= weapons_config[equiped].magazin_size;
        weapon->loaded_ammos = weapons_config[equiped].magazin_size;
    }
    animator_play_animation(sprite_datas->animator,
        get_survivor_anim_by_type(survivor_datas, anim_reload).name);
    sound_manager_play_sound(survivor_datas->sound_mgr,
        weapons_config[equiped].sound_reload);
    survivor_datas->weapon_mgr->timestamp_wait = timestamp +
        (uint64_t)(weapons_config[weapon->type].reload_time * 100000);
}

void weapon_reload(sprite *sprite_datas, uint64_t timestamp)
{
    survivor_s *survivor_datas = sprite_datas->datas;
    weapons_type_e equiped = survivor_datas->weapon_mgr->equiped_weapon;
    weapon_s *weapon = &survivor_datas->weapon_mgr->weapons[equiped];

    if (weapon->loaded_ammos >= weapons_config[equiped].magazin_size ||
        weapon->ammos == 0)
        return;
    reload_methode(weapon, equiped, sprite_datas, timestamp);
    weapon_hud_update(sprite_datas->host, survivor_datas);
}
