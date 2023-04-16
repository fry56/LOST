/*
** EPITECH PROJECT, 2023
** sound_manager_stop_sound.c
** File description:
** desc
*/

#include <Class/t_sound.h>
#include <t_string.h>
#include <Class/t_sound_manager.h>

void sound_manager_stop_sound(sound_mananger *self, char *name)
{
    sound_manager_player *player;

    list_foreach(self->list_sound_manager_player, node) {
        player = node->value;
        if (!tstr_cmp(player->sound_datas->name, name) && !player->destroy) {
            sfSound_stop(player->sf_sound);
            sound_manager_destroy_player(player);
        }
    }
}
