/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-jules.danet
** File description:
** windowed.c
*/

#include <t_ctype.h>
#include "survivor/survivor.h"
#include <functions.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>
#include "t_string.h"

static void button_hover_win(sprite *data, sfClock *clock UNUSED)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_over(data, &data->host->host->event))
        return;
    animator_play_animation(animator_data, "hover_windowed");
}

static void button_click_win(sprite *data, window *window_datas)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_click(data, &window_datas->event))
        return;
    animator_play_animation(animator_data, "click_windowed");
    sfRenderWindow_close(window_datas->window);
    window_datas->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
    "LOST", sfClose, NULL);
}

void init_windowed_button(sprite *button_windowed)
{
    animator *animator_windowed;
    animation *default_windowed;
    animation *hover_windowed;
    animation *click_windowed;
    sprite_set_fixed_origin(button_windowed, (sfVector2f){99, 31});
    sprite_set_pos(button_windowed, (sfVector2f){630, 395});
    animator_windowed = new_animator(button_windowed);
    default_windowed = new_animation("default_windowed",
    NULL, true, 10);
    animation_add_frame(default_windowed, (sfIntRect){0, 0, 187, 32});
    animator_add_animation(animator_windowed, default_windowed);
    animator_set_default(animator_windowed, "default_windowed");
    hover_windowed = new_animation("hover_windowed", NULL, false, 10);
    animation_add_frame(hover_windowed, (sfIntRect){0, 32, 187, 32});
    animator_add_animation(animator_windowed, hover_windowed);
    click_windowed = new_animation("click_windowed", NULL, false, 10);
    animation_add_frame(click_windowed, (sfIntRect){0, 64, 187, 32});
    animator_add_animation(animator_windowed, click_windowed);
    sprite_add_event_update_function(button_windowed, button_click_win);
    sprite_add_clock_update_function(button_windowed, button_hover_win);
}
