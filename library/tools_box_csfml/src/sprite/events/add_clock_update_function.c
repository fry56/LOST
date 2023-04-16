/*
** EPITECH PROJECT, 2023
** add_clock_update_function.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <stdlib.h>
#include <Class/t_window.h>

bool sprite_add_clock_update_function(sprite *self
        , void (*clock_update_function)(sprite *sprite_datas, sfClock *clock))
{
    if (tlist_add(self->list_clock_update_functions
            , clock_update_function) == NULL)
        return false;
    return true;
}
