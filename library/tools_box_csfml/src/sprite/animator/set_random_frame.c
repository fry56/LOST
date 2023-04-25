/*
** EPITECH PROJECT, 2023
** set_random_frame.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <Class/t_sprite_animator.h>
#include <stdlib.h>

void animator_set_random_frame(animator *self)
{
    self->animation_frame = rand() %
        ((animation *)self->played_animation->value)->list_frame_rect->length;
}
