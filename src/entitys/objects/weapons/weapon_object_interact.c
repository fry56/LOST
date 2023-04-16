/*
** EPITECH PROJECT, 2023
** weapon_object_interact.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <survivor/weapon/weapon_config.h>
#include <survivor/survivor.h>
#include <interaction.h>
#include <notifications.h>

static void add_weapon(weapon_object_s *weapon, sprite *sprite_datas,
    interaction_s *interaction_datas)
{
    survivor_s *survivor_datas = sprite_datas->datas;

    survivor_datas->weapon_mgr->weapons[weapon->type].unlock = true;
    survivor_datas->weapon_mgr->weapons[weapon->type].loaded_ammos =
        weapon->loaded_ammos;
    survivor_datas->weapon_mgr->equiped_weapon = weapon->type;
    weapon_set(sprite_datas, weapon->type);
    sprite_destroy(interaction_datas->host);
    sound_manager_play_sound(survivor_datas->sound_mgr, "sound_survivor_grab");
    new_notification(sprite_datas->host, "New weapon Unlock", 5);
}

static void add_weapon_ammos(weapon_object_s *weapon, sprite *sprite_datas,
    interaction_s *interaction_datas)
{
    survivor_s *survivor_datas = sprite_datas->datas;
    weapon_config_s config = weapons_config[weapon->type];
    weapons_manager_s *weapon_mgr = survivor_datas->weapon_mgr;
    weapon_object_s *weapon_obj = interaction_datas->datas;
    int free_ammos_slot;

    if (weapon_mgr->weapons[weapon->type].ammos >= config.max_ammos ||
        weapon_obj->loaded_ammos < 0)
        return;
    free_ammos_slot = config.max_ammos -
        weapon_mgr->weapons[weapon->type].ammos;
    if (free_ammos_slot >= weapon_obj->loaded_ammos) {
        weapon_mgr->weapons[weapon->type].ammos += weapon_obj->loaded_ammos;
        weapon_obj->loaded_ammos = 0;
    } else {
        weapon_mgr->weapons[weapon->type].ammos += free_ammos_slot;
        weapon_obj->loaded_ammos -= free_ammos_slot;
    }
    sound_manager_play_sound(survivor_datas->sound_mgr, "sound_survivor_grab");
}

void weapon_object_interact(sprite *sprite_datas,
    interaction_s *interaction_datas)
{
    survivor_s *survivor_datas = sprite_datas->datas;
    weapon_object_s *weapon = interaction_datas->datas;
    weapons_manager_s *weapon_mgr = survivor_datas->weapon_mgr;

    if (!weapon_mgr->weapons[weapon->type].unlock)
        add_weapon(weapon, sprite_datas, interaction_datas);
    if (((weapon_object_s *)interaction_datas->datas)->loaded_ammos > 0)
        add_weapon_ammos(weapon, sprite_datas, interaction_datas);
}
