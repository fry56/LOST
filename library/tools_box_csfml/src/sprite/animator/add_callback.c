/*
** EPITECH PROJECT, 2022
** add_callback.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <stdlib.h>
#include <Class/t_sprite_animator.h>
#include <t_mem.h>
#include <t_assert.h>

bool animator_add_callback(animator *self, char *animation_name
    , void (*callback_func)(sprite *sprite_pointer))
{
    animation_callback *new_callback;

    if (!animator_have_animation(self, animation_name))
        return false;
    tassert((new_callback = tcalloc(1, sizeof(animation_callback))) == NULL);
    new_callback->animation_name = animation_name;
    new_callback->callback = callback_func;
    tlist_add(self->list_callback, new_callback);
    return true;
}
