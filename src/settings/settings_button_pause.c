/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-jules.danet
** File description:
** settings_button.c
*/

#include <t_ctype.h>
#include "survivor/survivor.h"
#include <functions.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>

static void button_settings_hover(sprite *data, sfClock *clock UNUSED)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_over(data, &data->host->host->event))
        return;
    animator_play_animation(animator_data, "pause_set_hover");
}

static void button_settings_click(sprite *data, window *window_datas)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_click(data, &window_datas->event))
        return;
    animator_play_animation(animator_data, "pause_set_click");
    window_change_scene(window_datas, "settings_menu");
}

void init_settings_pause_button(sprite *settings_button)
{
    animator *settings_pause_animator;
    animation *settings_pause_default;
    animation *settings_pause_hover;
    animation *settings_pause_click;
    sprite_set_fixed_origin(settings_button, (sfVector2f){99, 31});
    sprite_set_pos(settings_button, (sfVector2f){240, 500});
    settings_pause_animator = new_animator(settings_button);
    settings_pause_default = new_animation("pause_set_default",
    NULL, true, 10);
    animation_add_frame(settings_pause_default, (sfIntRect){0, 0, 138, 40});
    animator_add_animation(settings_pause_animator, settings_pause_default);
    animator_set_default(settings_pause_animator, "pause_set_default");
    settings_pause_hover = new_animation("pause_set_hover", NULL, false, 10);
    animation_add_frame(settings_pause_hover, (sfIntRect){0, 40, 138, 40});
    animator_add_animation(settings_pause_animator, settings_pause_hover);
    settings_pause_click = new_animation("pause_set_click", NULL, false, 10);
    animation_add_frame(settings_pause_click, (sfIntRect){0, 80, 138, 40});
    animator_add_animation(settings_pause_animator, settings_pause_click);
    sprite_add_event_update_function(settings_button, button_settings_click);
    sprite_add_clock_update_function(settings_button, button_settings_hover);
}
