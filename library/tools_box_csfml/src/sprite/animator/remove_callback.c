/*
** EPITECH PROJECT, 2022
** remove_event.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <Class/t_sprite_animator.h>
#include <stdlib.h>
#include <t_string.h>

bool animator_remove_callback(animator *self, tsize_t index)
{
    tsize_t i = 0;

    if (self->list_callback->length < index)
        return false;
    list_foreach(self->list_callback, node) {
        if (i == index) {
            free(node->value);
            tlist_remove(self->list_callback, node);
            break;
        }
        i++;
    }
    return true;
}

void animator_remove_callback_by_name(animator *self, char *animation_name)
{
    list_foreach(self->list_callback, node) {
        if (tstr_cmp(((animation_callback *)node->value)->animation_name
            , animation_name) == 0) {
            tlist_remove(self->list_callback, node);
        }
    }
}
