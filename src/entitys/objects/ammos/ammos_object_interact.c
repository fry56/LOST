/*
** EPITECH PROJECT, 2023
** ammos_object_interact.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <survivor/weapon/weapon_config.h>
#include <survivor/survivor.h>
#include <interaction.h>
#include <notifications.h>

void ammos_object_interact(sprite *sprite_datas,
    interaction_s *interaction_datas)
{
    survivor_s *survivor_datas = sprite_datas->datas;
    ammos_object_s *ammos = interaction_datas->datas;
    weapon_config_s config = weapons_config[ammos->type];
    weapons_manager_s *weapon_mgr = survivor_datas->weapon_mgr;

    if (weapon_mgr->weapons[ammos->type].ammos >= config.max_ammos)
        return;
    weapon_add_ammos(sprite_datas, ammos->type, config.magazin_size);
    sprite_destroy(interaction_datas->host);
    sound_manager_play_sound(survivor_datas->sound_mgr, "sound_survivor_grab");
}
