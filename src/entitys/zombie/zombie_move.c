/*
** EPITECH PROJECT, 2023
** zombie_move.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <zombie/zombie.h>
#include <utils.h>

void zombie_move(sprite *sprite_datas, sfVector2f pos UNUSED)
{
    zombie_s *zombie_datas = sprite_datas->datas;

    sound_manager_set_pos(zombie_datas->sound_mgr, sprite_datas->pos);
    box_collider_set_pos(zombie_datas->box_collider, sprite_datas->pos);
}
