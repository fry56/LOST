/*
** EPITECH PROJECT, 2023
** sound_manager_destroy.c
** File description:
** desc
*/

#include <t_mem.h>
#include <t_string.h>
#include <Class/t_sound_manager.h>

void sound_manager_garbage_destroy(void *self)
{
    sound_mananger *sound_mgr = self;

    thashmap_clear(sound_mgr->map_sound);
    list_foreach(sound_mgr->list_sound_manager_player, node)
        sound_manager_destroy_player(node->value);
}

void sound_manager_destroy(sound_mananger *self)
{
    window_add_garbage(self->host->host, self->node_sound_manager,
        sound_manager_garbage_destroy);
}
