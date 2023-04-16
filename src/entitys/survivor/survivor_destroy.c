/*
** EPITECH PROJECT, 2023
** destroy_survivor.c
** File description:
** desc
*/

#include "Class/t_sprite.h"
#include "t_mem.h"
#include <survivor/survivor.h>

void survivor_destroy(sprite *sprite_datas)
{
    survivor_s *survivor_datas = sprite_datas->datas;
    free(survivor_datas->weapon_mgr);
    sound_manager_destroy(survivor_datas->sound_mgr);
    free(sprite_datas->datas);
}
