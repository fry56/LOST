/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-jules.danet
** File description:
** full_screen.c
*/

#include <t_ctype.h>
#include "survivor/survivor.h"
#include <functions.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>
#include "t_string.h"

static void button_hover_full(sprite *data, sfClock *clock UNUSED)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_over(data, &data->host->host->event))
        return;
    animator_play_animation(animator_data, "hover_fullscreen");
}

static void button_click_full(sprite *data, window *window_datas)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_click(data, &window_datas->event))
        return;
    animator_play_animation(animator_data, "click_fullscreen");
    sfRenderWindow_close(window_datas->window);
    window_datas->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
    "LOST", sfFullscreen, NULL);
}

void init_fullscreen_button(sprite *button_fullscreen)
{
    animator *animator_fullscreen;
    animation *default_fullscreen;
    animation *hover_fullscreen;
    animation *click_fullscreen;
    sprite_set_fixed_origin(button_fullscreen, (sfVector2f){99, 31});
    sprite_set_pos(button_fullscreen, (sfVector2f){880, 395});
    animator_fullscreen = new_animator(button_fullscreen);
    default_fullscreen = new_animation("default_fullscreen",
    NULL, true, 10);
    animation_add_frame(default_fullscreen, (sfIntRect){0, 0, 176, 32});
    animator_add_animation(animator_fullscreen, default_fullscreen);
    animator_set_default(animator_fullscreen, "default_fullscreen");
    hover_fullscreen = new_animation("hover_fullscreen", NULL, false, 10);
    animation_add_frame(hover_fullscreen, (sfIntRect){0, 32, 176, 32});
    animator_add_animation(animator_fullscreen, hover_fullscreen);
    click_fullscreen = new_animation("click_fullscreen", NULL, false, 10);
    animation_add_frame(click_fullscreen, (sfIntRect){0, 64, 176, 32});
    animator_add_animation(animator_fullscreen, click_fullscreen);
    sprite_add_event_update_function(button_fullscreen, button_click_full);
    sprite_add_clock_update_function(button_fullscreen, button_hover_full);
}
