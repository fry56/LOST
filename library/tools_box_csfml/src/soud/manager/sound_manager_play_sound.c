/*
** EPITECH PROJECT, 2023
** sound_manager_play_sound.c
** File description:
** desc
*/

#include <Class/t_sound.h>
#include <t_string.h>
#include <Class/t_sound_manager.h>
#include <t_assert.h>
#include <t_mem.h>

static bool play_sound(sound_mananger *self, sound *temp)
{
    sound_manager_player *player;

    list_foreach(self->list_sound_manager_player, node) {
        player = node->value;
        if (player->sound_datas == temp && !temp->over_play) {
            return false;
        }
        if (player->sound_datas == temp && temp->over_play) {
            sfSound_stop(player->sf_sound);
            sound_manager_destroy_player(node->value);
            return true;
        }
    }
    return true;
}

static void init_player_datas(sound_mananger *self,
    sound_manager_player *player, sound *temp)
{
    player->destroy = false;
    tassert((player->sf_sound = sfSound_create()) == NULL);
    player->timestamp_destroy = sfClock_getElapsedTime(self->host->host->
        global_clock).microseconds + temp->duration;
    sfSound_setBuffer(player->sf_sound, temp->sf_sound_buffer);
    sfSound_setMinDistance(player->sf_sound, temp->min_dist > 0 ?
        temp->min_dist : self->min_dist);
    sfSound_setVolume(player->sf_sound, temp->volume > 0 ?
        temp->volume : self->volume);
    sfSound_setLoop(player->sf_sound, temp->loop);
    sfSound_play(player->sf_sound);
    player->node_sound_manager_player =
        tlist_add(self->list_sound_manager_player, player);
}

bool sound_manager_play_sound(sound_mananger *self, char *name)
{
    t_hashmap_node *sound_node;
    sound *temp;
    sound_manager_player *player;

    if ((sound_node = thashmap_get(self->map_sound, name)) == NULL)
        return false;
    temp = sound_node->value;
    if (!play_sound(self, temp))
        return false;
    tassert((player = tcalloc(1, sizeof(sound_manager_player))) == NULL);
    player->host = self;
    player->sound_datas = temp;
    init_player_datas(self, player, temp);
    return true;
}
