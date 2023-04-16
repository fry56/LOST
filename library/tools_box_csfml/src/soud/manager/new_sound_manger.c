/*
** EPITECH PROJECT, 2023
** new_sound_manger.c
** File description:
** desc
*/

#include <t_mem.h>
#include <t_assert.h>
#include <t_string.h>
#include <Class/t_sound_manager.h>
#include <SFML/Audio.h>
#include <Class/t_scene.h>

void clear_sound_manager_player(sound_mananger *self, sfClock *clock)
{
    sound_manager_player *temp;
    uint64_t timestamp = sfClock_getElapsedTime(clock).microseconds;

    list_foreach(self->list_sound_manager_player, node) {
        temp = node->value;

        if (temp->timestamp_destroy < timestamp)
            sound_manager_destroy_player(temp);
    }
}

sound_mananger *new_sound_manager(scene *scene_datas, sfVector2f pos,
    float min_dist, float volume)
{
    sound_mananger *temp = tcalloc(2, sizeof(sound_mananger));

    tassert(temp == NULL);
    temp->map_sound = thashmap_new(32);
    temp->list_sound_manager_player = tlist_new();
    temp->min_dist = min_dist;
    temp->volume = volume;
    temp->host = scene_datas;
    temp->pos = pos;
    temp->node_sound_manager = tlist_add(scene_datas->list_sound_manager, temp);
    return temp;
}
