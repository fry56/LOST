/*
** EPITECH PROJECT, 2023
** sound_manager_set_pos.c
** File description:
** desc
*/

#include <Class/t_sound.h>
#include <t_string.h>
#include <Class/t_sound_manager.h>

void sound_manager_set_pos(sound_mananger *self, sfVector2f pos)
{
    self->pos = pos;
    list_foreach(self->list_sound_manager_player, node) {
        sfSound_setPosition(((sound_manager_player *)node->value)->sf_sound,
            (sfVector3f){pos.x, pos.y, 0});
    }
}
