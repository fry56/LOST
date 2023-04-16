/*
** EPITECH PROJECT, 2022
** add_event.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <stdlib.h>
#include <Class/t_window.h>

bool sprite_add_event_update_function(sprite *self
    , void (*event_update_function)(sprite *sprite_datas, struct window *))
{
    if (tlist_add(self->list_event_update_functions
        , event_update_function) == NULL) {
        return false;
    }
    return true;
}
