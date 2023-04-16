/*
** EPITECH PROJECT, 2023
** init_window.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <Class/t_sprite.h>
#include <Class/t_text.h>
#include <stdlib.h>

static void window_update_entity(window *self)
{
    sfRenderWindow_setView(self->window,
        ((scene *)self->actual_scene->value)->view);
    list_foreach(((scene *)self->actual_scene->value)->list_sprites, node) {
        if (!((sprite *) node->value)->visible)
            continue;
        sfRenderWindow_drawSprite(self->window
            , ((sprite *)node->value)->sf_sprite, NULL);
    }
    list_foreach(((scene *)self->actual_scene->value)->list_texts, node) {
        if (!((text *) node->value)->visible)
            continue;
        sfRenderWindow_drawText(self->window, ((text *) node->value)->sf_text,
            NULL);
    }
}

static void free_garbage(window *self)
{
    list_foreach(self->list_node_garbage, node) {
        tlist_remove(((garbage *)node->value)->node->host,
            ((garbage *)node->value)->node);
        ((garbage *)node->value)->destroy(
            ((garbage *)node->value)->node->value);
        free(node->value);
    }
    tlist_clear(self->list_node_garbage);
}

int window_start(window *self)
{
    while (sfRenderWindow_isOpen(self->window)) {
        free_garbage(self);
        while (sfRenderWindow_pollEvent(self->window, &self->event))
            window_event_update(self);
        window_clock_update(self);
        sfRenderWindow_clear(self->window, sfBlack);
        window_update_entity(self);
        sfRenderWindow_display(self->window);
        self->deltatime = ((float)sfClock_getElapsedTime(self->global_clock)
            .microseconds - (float)self->last_tick) / 10000;
        self->last_tick = sfClock_getElapsedTime(self->global_clock)
            .microseconds;
    }
    window_destroy(self);
    return 0;
}
