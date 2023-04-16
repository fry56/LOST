/*
** EPITECH PROJECT, 2022
** remove_event.c
** File description:
** desc
*/

#include <Class/t_sprite.h>

bool sprite_remove_event_update_function(sprite *self
        , void (*event_update_function)(sprite *scene_datas, struct window *))
{
    list_foreach(self->list_event_update_functions,node) {
        if (node->value == event_update_function) {
            tlist_remove(self->list_event_update_functions, node);
            return true;
        }
    }
    return false;
}
