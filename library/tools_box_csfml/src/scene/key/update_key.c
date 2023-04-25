/*
** EPITECH PROJECT, 2023
** update_key.c
** File description:
** desc
*/

#include <t_ctype.h>
#include <Utils/t_key.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>

void scene_update_key(scene *self, window *window_datas)
{
    sfEvent event = window_datas->event;
    key_bind *key = scene_get_key(self, event.key.code);

    if (key == NULL)
        return;
    key->is_press = (window_datas->event.type == sfEvtKeyPressed);
    if (key->is_press)
        key->timestamp = sfClock_getElapsedTime(window_datas->global_clock)
            .microseconds;
}
