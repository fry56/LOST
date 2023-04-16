/*
** EPITECH PROJECT, 2023
** remove_clock_update_function.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <Class/t_window.h>

bool sprite_remove_clock_update_function(sprite *self
        , void (*clock_update_function)(sprite *sprite_datas, sfClock *clock))
{
    list_foreach(self->list_clock_update_functions, node) {
        if (node->value == clock_update_function) {
            tlist_remove(self->list_clock_update_functions, node);
            return true;
        }
    }
    return false;
}
