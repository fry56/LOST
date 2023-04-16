/*
** EPITECH PROJECT, 2023
** sound_destroy.c
** File description:
** desc
*/

#include <Class/t_sound.h>
#include <t_mem.h>

void sound_destroy(sound *self)
{
    sfSoundBuffer_destroy(self->sf_sound_buffer);
    free(self->name);
    free(self);
}
