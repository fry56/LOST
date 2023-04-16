/*
** EPITECH PROJECT, 2022
** inti.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <t_mem.h>
#include <t_assert.h>

static void init_window(window *self)
{
    sfRenderWindow_setFramerateLimit(self->window, 60);
    self->map_scenes = thashmap_new(1024);
    self->map_datas = thashmap_new(1024);
    self->list_node_garbage = tlist_new();
    self->actual_scene = NULL;
    self->last_tick = 0;
    self->deltatime = 0;
}

window *new_window(char *name, sfVideoMode mode)
{
    window *new_window = tcalloc(1, sizeof(window));

    tassert(new_window == NULL);
    new_window->mode = mode;
    new_window->window = sfRenderWindow_create(mode, name
        , sfClose, NULL);
    t_assert(!new_window->window);
    init_window(new_window);
    return new_window;
}
