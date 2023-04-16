/*
** EPITECH PROJECT, 2023
** update.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <Class/t_sprite.h>

void call_update_sprite_clock(sprite *sprite_datas, sfClock *clock)
{
    list_foreach(sprite_datas->list_clock_update_functions, node) {
        ((void (*)(sprite *sprite_datas, sfClock *clock))node->value)
            (sprite_datas, clock);
    }
}

void call_update_sprite_event(sprite *sprite_datas, window *window_datas)
{
    list_foreach(sprite_datas->list_event_update_functions, node) {
        ((void (*)(sprite *sprite_datas, struct window *))node->value)
                (sprite_datas, window_datas);
    }
}
