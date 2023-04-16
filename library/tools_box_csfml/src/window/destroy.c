/*
** EPITECH PROJECT, 2022
** destroy.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <Class/t_sprite.h>
#include <Class/t_text.h>

void scene_destroy_foreach(char *key, void *value)
{
    scene_destroy(value);
}

void window_destroy(window *self)
{
    thashmap_foreach(self->map_scenes, scene_destroy_foreach);
    thashmap_free(self->map_scenes);
    sfClock_destroy(self->global_clock);
    sfRenderWindow_destroy(self->window);
}
