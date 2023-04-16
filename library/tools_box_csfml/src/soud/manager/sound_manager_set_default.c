/*
** EPITECH PROJECT, 2023
** sound_manager_set_default.c
** File description:
** desc
*/

#include <Class/t_sound.h>
#include <t_string.h>
#include <Class/t_sound_manager.h>

bool sound_manager_set_default(sound_mananger *self, char *name)
{
    t_hashmap_node *node_sound = thashmap_get(self->map_sound, name);

    if (node_sound == NULL)
        return false;
    self->node_default_sound = node_sound;
    return true;
}
