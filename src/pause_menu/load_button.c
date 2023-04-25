/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-jules.danet
** File description:
** quit_game.c
*/

#include <t_ctype.h>
#include "survivor/survivor.h"
#include <functions.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>

static void button_load_hover(sprite *data, sfClock *clock UNUSED)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_over(data, &data->host->host->event))
        return;
    if (!survivor_have_save())
        return;
    animator_play_animation(animator_data, "load_quit_hover");
}

static void button_load_click(sprite *data, window *window_datas)
{
    animator *animator_data = data->animator;
    survivor_s *survivor_datas;
    if (window_datas->event.type != sfEvtMouseButtonPressed)
        return;
    if (!sprite_is_mouse_click(data, &window_datas->event))
        return;
    if (!survivor_have_save())
        return;
    survivor_datas = thashmap_get(
            data->host->host->map_datas, "SURVIVOR_DATAS")->value;
    animator_play_animation(animator_data, "load_quit_click");
    survivor_load_save(survivor_datas);
}

void init_load_pause_button(sprite *quit_button)
{
    animator *load_pause_animator;
    animation *load_pause_default;
    animation *load_hover;
    animation *load_click;
    sprite_set_fixed_origin(quit_button, (sfVector2f){93, 40});
    sprite_set_pos(quit_button, (sfVector2f){235, 813});
    load_pause_animator = new_animator(quit_button);
    load_pause_default = new_animation("load_quit_default",
        NULL, true, 10);
    animation_add_frame(load_pause_default, (sfIntRect){0, 0, 189, 37});
    animator_add_animation(load_pause_animator, load_pause_default);
    animator_set_default(load_pause_animator, "load_quit_default");
    load_hover = new_animation("load_quit_hover", NULL, false, 10);
    animation_add_frame(load_hover, (sfIntRect){0, 40,  189, 37});
    animator_add_animation(load_pause_animator, load_hover);
    load_click = new_animation("load_quit_click", NULL, false, 10);
    animation_add_frame(load_click, (sfIntRect){0, 80,  189, 37});
    animator_add_animation(load_pause_animator, load_click);
    sprite_add_event_update_function(quit_button, button_load_click);
    sprite_add_clock_update_function(quit_button, button_load_hover);
}
