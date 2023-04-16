/*
** EPITECH PROJECT, 2023
** new_sound.c
** File description:
** desc
*/

#include <Class/t_sound.h>
#include <t_mem.h>
#include <t_assert.h>
#include <t_string.h>

sound *new_sound(char *name, char *path, float min_dist, float volume)
{
    sound *temp = tcalloc(1, sizeof(sound));

    tassert(temp == NULL);
    temp->name = tstr_cpy(NULL, name);
    temp->sf_sound_buffer = sfSoundBuffer_createFromFile(path);
    temp->min_dist = min_dist >= 0 ? min_dist : 0;
    temp->volume = volume >= 0 ? volume : 0;
    temp->loop = false;
    temp->over_play = false;
    temp->duration =
        sfSoundBuffer_getDuration(temp->sf_sound_buffer).microseconds;
    tassert(temp->sf_sound_buffer == NULL);
    return temp;
}
