/*
** EPITECH PROJECT, 2023
** sound_manager_destroy_player.c
** File description:
** desc
*/

#include <Class/t_sound_manager.h>
#include <Class/t_window.h>

void sound_manager_player_garbage_destroy(void *self)
{
    sound_manager_player *player = self;

    sfSound_destroy(player->sf_sound);
    tlist_remove(((t_list_node *)self)->host,
        player->node_sound_manager_player);
}

void sound_manager_destroy_player(sound_manager_player *self)
{
    if (self->destroy)
        return;
    window_add_garbage(self->host->host->host, self->node_sound_manager_player,
        sound_manager_player_garbage_destroy);
    self->destroy = true;
}
