/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-jules.danet
** File description:
** minus_music.c
*/

#include <t_ctype.h>
#include "survivor/survivor.h"
#include <functions.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>
#include "t_string.h"

static void button_hover_minus_music(sprite *data, sfClock *clock UNUSED)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_over(data, &data->host->host->event))
        return;
    animator_play_animation(animator_data, "hover_minus_music");
}

static void button_click_minus_music(sprite *data, window *window_datas)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_click(data, &window_datas->event))
        return;
    animator_play_animation(animator_data, "click_minus_music");
}

void init_minus_music_button(sprite *minus_music)
{
    animator *animator_minus_music;
    animation *default_minus_music;
    animation *hover_minus_music;
    animation *click_minus_music;
    sprite_set_fixed_origin(minus_music, (sfVector2f){99, 31});
    sprite_set_pos(minus_music, (sfVector2f){850, 820});
    animator_minus_music = new_animator(minus_music);
    default_minus_music = new_animation("default_minus_music",
    NULL, true, 10);
    animation_add_frame(default_minus_music, (sfIntRect){0, 0, 68, 61});
    animator_add_animation(animator_minus_music, default_minus_music);
    animator_set_default(animator_minus_music, "default_minus_music");
    hover_minus_music = new_animation("hover_minus_music", NULL, false, 10);
    animation_add_frame(hover_minus_music, (sfIntRect){0, 61, 68, 61});
    animator_add_animation(animator_minus_music, hover_minus_music);
    click_minus_music = new_animation("click_minus_music", NULL, false, 10);
    animation_add_frame(click_minus_music, (sfIntRect){0, 122, 68, 61});
    animator_add_animation(animator_minus_music, click_minus_music);
    sprite_add_event_update_function(minus_music, button_click_minus_music);
    sprite_add_clock_update_function(minus_music, button_hover_minus_music);
}
