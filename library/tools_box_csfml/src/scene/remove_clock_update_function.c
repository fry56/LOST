/*
** EPITECH PROJECT, 2022
** remove_clock_update_function.cpp
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <Class/t_window.h>

bool scene_remove_clock_update_function(scene *self
    , void (*clock_update_function)(scene *scene_datas, sfClock *clock))
{
    list_foreach(self->list_clock_update_functions, node) {
        if (node->value == clock_update_function) {
            tlist_remove(self->list_clock_update_functions, node);
            return true;
        }
    }
    return false;
}
