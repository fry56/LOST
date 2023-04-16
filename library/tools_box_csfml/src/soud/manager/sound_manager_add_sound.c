/*
** EPITECH PROJECT, 2023
** sound_manager_add_sound.c
** File description:
** desc
*/

#include <Class/t_sound.h>
#include <t_mem.h>
#include <t_string.h>
#include <Class/t_sound_manager.h>

bool sound_manager_add_sound(sound_mananger *self, sound *sound_datas)
{
    t_hashmap_node *temp = thashmap_add(self->map_sound,
        sound_datas->name, sound_datas);

    if (temp == NULL)
        return false;
    return true;
}
