/*
** EPITECH PROJECT, 2023
** zombie_set_pos.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <zombie/zombie.h>

void zombie_set_pos(sprite *sprite_datas, sfVector2f pos UNUSED)
{
    sound_manager_set_pos(((zombie_s *)sprite_datas->datas)->sound_mgr,
        sprite_datas->pos);
}
