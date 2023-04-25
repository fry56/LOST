/*
** EPITECH PROJECT, 2023
** weapon_hud_move.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <Class/t_text.h>
#include <hud/weapon_hud.h>

void weapon_hud_move(sprite *sprite_datas, sfVector2f pos)
{
    weapon_hud_s *hud = sprite_datas->datas;

    text_move(hud->description, pos);
}
