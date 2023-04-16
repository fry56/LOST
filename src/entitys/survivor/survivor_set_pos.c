/*
** EPITECH PROJECT, 2023
** set_pos_survivor.c
** File description:
** desc
*/

#include "Class/t_sprite.h"
#include "Class/t_sound_manager.h"
#include "survivor/survivor.h"

void survivor_set_pos(sprite *sprite_datas, sfVector2f pos)
{
    survivor_s *survivor_datas = sprite_datas->datas;

    sfListener_setPosition((sfVector3f){pos.x, pos.y, 0});
    sound_manager_set_pos(survivor_datas->sound_mgr, sprite_datas->pos);
    sfView_setCenter(sprite_datas->host->view,
        (sfVector2f){pos.x, pos.y});
}
