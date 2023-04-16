/*
** EPITECH PROJECT, 2023
** sound_manager_clear.c
** File description:
** desc
*/

#include <t_string.h>
#include <Class/t_sound_manager.h>

void sound_manager_clear(sound_mananger *self)
{
    list_foreach(self->list_sound_manager_player, node)
        sound_manager_destroy_player(node->value);
}
