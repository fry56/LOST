/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-jules.danet
** File description:
** minus_sound.c
*/

#include <t_ctype.h>
#include "survivor/survivor.h"
#include <functions.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>
#include "t_string.h"

static void button_hover_minus_sound(sprite *data, sfClock *clock UNUSED)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_over(data, &data->host->host->event))
        return;
    animator_play_animation(animator_data, "hover_minus_sound");
}

static void button_click_minus_sound(sprite *data, window *window_datas)
{
    animator *animator_data = data->animator;
    float sound = sfListener_getGlobalVolume();

    if (!sprite_is_mouse_click(data, &window_datas->event))
        return;
    animator_play_animation(animator_data, "click_minus_sound");
    if (sound != 0)
        sfListener_setGlobalVolume(sound - 1);
}

void init_minus_sound_button(sprite *minus_sound)
{
    animator *animator_minus_sound;
    animation *default_minus_sound;
    animation *hover_minus_sound;
    animation *click_minus_sound;
    sprite_set_fixed_origin(minus_sound, (sfVector2f){99, 31});
    sprite_set_pos(minus_sound, (sfVector2f){850, 710});
    animator_minus_sound = new_animator(minus_sound);
    default_minus_sound = new_animation("default_minus_sound",
    NULL, true, 10);
    animation_add_frame(default_minus_sound, (sfIntRect){0, 0, 68, 61});
    animator_add_animation(animator_minus_sound, default_minus_sound);
    animator_set_default(animator_minus_sound, "default_minus_sound");
    hover_minus_sound = new_animation("hover_minus_sound", NULL, false, 10);
    animation_add_frame(hover_minus_sound, (sfIntRect){0, 61, 68, 61});
    animator_add_animation(animator_minus_sound, hover_minus_sound);
    click_minus_sound = new_animation("click_minus_sound", NULL, false, 10);
    animation_add_frame(click_minus_sound, (sfIntRect){0, 122, 68, 61});
    animator_add_animation(animator_minus_sound, click_minus_sound);
    sprite_add_event_update_function(minus_sound, button_click_minus_sound);
    sprite_add_clock_update_function(minus_sound, button_hover_minus_sound);
}
