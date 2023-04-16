/*
** EPITECH PROJECT, 2023
** sound_manager_remove_sound.c
** File description:
** desc
*/

#include <Class/t_sound.h>
#include <t_string.h>
#include <Class/t_sound_manager.h>

void sound_manager_remove_sound(sound_mananger *self, char *name)
{
    thashmap_remove(self->map_sound, name);
}
