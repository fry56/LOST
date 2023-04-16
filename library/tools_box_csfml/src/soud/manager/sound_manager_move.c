/*
** EPITECH PROJECT, 2023
** sound_manager_move.c
** File description:
** desc
*/

#include <Class/t_sound.h>
#include <t_string.h>
#include <Class/t_sound_manager.h>

void sound_manager_move(sound_mananger *self, sfVector2f pos)
{
    self->pos = (sfVector2f){self->pos.x + pos.x, self->pos.y + pos.y};
    list_foreach(self->list_sound_manager_player, node) {
        sfSound_setPosition(((sound_manager_player *)node->value)->sf_sound,
            (sfVector3f){self->pos.x, self->pos.y, 0});
    }
}
