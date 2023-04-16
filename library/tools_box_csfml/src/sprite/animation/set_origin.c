/*
** EPITECH PROJECT, 2023
** set_origin.c
** File description:
** desc
*/

#include <Class/t_sprite.h>

void animation_set_origin(animation *self, sfVector2f pos)
{
    self->custom_origin = true;
    self->origin = pos;
}
