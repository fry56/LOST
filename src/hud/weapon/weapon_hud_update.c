/*
** EPITECH PROJECT, 2023
** weapon_hud_update.c
** File description:
** desc
*/

#include <survivor/survivor.h>
#include <survivor/weapon/weapon.h>
#include <survivor/weapon/weapon_config.h>
#include <Class/t_text.h>
#include <t_string.h>
#include <stdlib.h>
#include <hud/weapon_hud.h>

void weapon_hud_update(scene *scene_datas, survivor_s *survivor_datas)
{
    sprite *hud_sprite = sprite_get_by_flag(scene_datas, "weapon_hud");
    weapon_hud_s *hud = hud_sprite->datas;

    char *temp = tstr_compos("%d/%d",
        survivor_datas->weapon_mgr->weapons[
            survivor_datas->weapon_mgr->equiped_weapon].loaded_ammos,
        survivor_datas->weapon_mgr->weapons[
            survivor_datas->weapon_mgr->equiped_weapon].ammos);

    sprite_set_texture(hud_sprite,
        weapons_config[survivor_datas->weapon_mgr->equiped_weapon].weapon_path);
    text_set_content(hud->description, temp);
    free(temp);
}
