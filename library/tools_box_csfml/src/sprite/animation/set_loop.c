/*
** EPITECH PROJECT, 2022
** set_loop.c
** File description:
** desc
*/

#include <Class/t_sprite_animation.h>

void animation_set_loop(animation *self, bool loop)
{
    self->loop = loop;
}
