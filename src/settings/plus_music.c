/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-jules.danet
** File description:
** plus_music.c
*/

#include <t_ctype.h>
#include "survivor/survivor.h"
#include <functions.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>
#include "t_string.h"

static void button_hover_plus_music(sprite *data, sfClock *clock UNUSED)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_over(data, &data->host->host->event))
        return;
    animator_play_animation(animator_data, "hover_plus_music");
}

static void button_click_plus_music(sprite *data, window *window_datas)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_click(data, &window_datas->event))
        return;
    animator_play_animation(animator_data, "click_plus_music");
}

void init_plus_music_button(sprite *plus_music)
{
    animator *animator_plus_music;
    animation *default_plus_music;
    animation *hover_plus_music;
    animation *click_plus_music;
    sprite_set_fixed_origin(plus_music, (sfVector2f){99, 31});
    sprite_set_pos(plus_music, (sfVector2f){980, 820});
    animator_plus_music = new_animator(plus_music);
    default_plus_music = new_animation("default_plus_music",
    NULL, true, 10);
    animation_add_frame(default_plus_music, (sfIntRect){0, 0, 68, 61});
    animator_add_animation(animator_plus_music, default_plus_music);
    animator_set_default(animator_plus_music, "default_plus_music");
    hover_plus_music = new_animation("hover_plus_music", NULL, false, 10);
    animation_add_frame(hover_plus_music, (sfIntRect){0, 61, 68, 61});
    animator_add_animation(animator_plus_music, hover_plus_music);
    click_plus_music = new_animation("click_plus_music", NULL, false, 10);
    animation_add_frame(click_plus_music, (sfIntRect){0, 122, 68, 61});
    animator_add_animation(animator_plus_music, click_plus_music);
    sprite_add_event_update_function(plus_music, button_click_plus_music);
    sprite_add_clock_update_function(plus_music, button_hover_plus_music);
}
