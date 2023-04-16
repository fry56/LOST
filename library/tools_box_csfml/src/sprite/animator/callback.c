/*
** EPITECH PROJECT, 2022
** callback.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <Class/t_sprite_animator.h>

void animator_callback(animator *self, char *animation_name)
{
    list_foreach(self->list_callback, node) {
        if (((animation_callback *)node->value)->animation_name ==
            animation_name)
            ((animation_callback *)node->value)->callback(self->host);
    }
}
