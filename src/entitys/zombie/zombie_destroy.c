/*
** EPITECH PROJECT, 2023
** zombie_destroy.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <zombie/zombie.h>
#include <stdlib.h>

void zombie_destroy(sprite *sprite_datas)
{
    sound_manager_destroy(((zombie_s *)sprite_datas->datas)->sound_mgr);
    free(sprite_datas->datas);
}
