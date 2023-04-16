/*
** EPITECH PROJECT, 2022
** set_frame_rate.c
** File description:
** desc
*/

#include <Class/t_sprite_animation.h>

bool animation_set_frame_rate(animation *self, float frame_rate)
{
    if (frame_rate < 0)
        return false;
    self->frame_rate = frame_rate;
    return true;
}
