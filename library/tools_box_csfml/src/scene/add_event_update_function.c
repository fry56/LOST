/*
** EPITECH PROJECT, 2022
** add_event_update_function.c
** File description:
** desc
*/


#include <Class/t_sprite.h>
#include <stdio.h>
#include <Class/t_window.h>

bool scene_add_event_update_function(scene *self
    , void (*event_update_function)(scene *scene_datas, window *window_datas))
{
    if (tlist_add(self->list_event_update_functions
            , event_update_function) == NULL)
        return false;
    return true;
}
