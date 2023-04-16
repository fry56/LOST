/*
** EPITECH PROJECT, 2022
** update.c
** File description:
** desc
*/

#include "Class/t_sprite.h"
#include "Class/t_window.h"
#include <Class/t_sprite_animator.h>

void clock_update_sprite(scene *scene_datas, sfClock *clock)
{
    list_foreach(scene_datas->list_sprites, node) {
        update_sprite_animator(((sprite *)node->value), clock);
        if (((sprite *)node->value)->list_clock_update_functions->length > 0)
            call_update_sprite_clock(((sprite *)node->value), clock);
    }
}

void event_update_sprite(scene *scene_datas, window *window_datas)
{
    list_foreach(scene_datas->list_sprites, node) {
        if (((sprite *)node->value)->list_event_update_functions->length > 0)
            call_update_sprite_event(((sprite *)node->value), window_datas);
    }
}
