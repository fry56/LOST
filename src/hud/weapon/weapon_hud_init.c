/*
** EPITECH PROJECT, 2023
** weapon_hud_init.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <Class/t_text.h>
#include <survivor/survivor.h>
#include <hud/weapon_hud.h>
#include <t_mem.h>

void weapon_hud_destroy(sprite *sprite_datas)
{
    text_destroy(sprite_datas->datas);
}

sprite *weapon_hud_init(scene *scene_datas, sfVector2f pos)
{
    sprite *weapon = new_sprite(scene_datas,
        "assets/sprites/items/weapons/weapon_ak47.png", 200);
    weapon_hud_s *hud = tcalloc(1, sizeof(weapon_hud_s));

    hud->pos = (sfVector2f){1750, 70};
    hud->description = new_text(scene_datas, "0/0",
        "assets/font/inter.woff2", (rgb){255, 255, 255});
    hud->host = weapon;
    sprite_add_flag(weapon, "weapon_hud");
    sprite_add_flag(weapon, "canva");
    sprite_set_pos(weapon, (sfVector2f){pos.x + 860, pos.y - 440});
    sprite_set_fixed_origin(weapon, (sfVector2f){0, 0});
    sfSprite_setScale(weapon->sf_sprite, (sfVector2f){1.5f, 1.5f});
    text_set_pos(hud->description, (sfVector2f){pos.x + 860, pos.y - 420});
    sfText_setOrigin(hud->description->sf_text, (sfVector2f){0, 0});
    weapon->move = weapon_hud_move;
    weapon->destroy = weapon_hud_destroy;
    weapon->datas = hud;
    return weapon;
}
