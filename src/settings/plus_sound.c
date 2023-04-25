/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-jules.danet
** File description:
** plus_sound.c
*/

#include <t_ctype.h>
#include "survivor/survivor.h"
#include <functions.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>
#include "t_string.h"

static void button_hover_plus_sound(sprite *data, sfClock *clock UNUSED)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_over(data, &data->host->host->event))
        return;
    animator_play_animation(animator_data, "hover_plus_sound");
}

static void button_click_plus_sound(sprite *data, window *window_datas)
{
    animator *animator_data = data->animator;
    float sound = sfListener_getGlobalVolume();

    if (!sprite_is_mouse_click(data, &window_datas->event))
        return;
    animator_play_animation(animator_data, "click_plus_sound");
    if (sound != 100)
        sfListener_setGlobalVolume(sound + 1);
}

void init_plus_sound_button(sprite *plus_sound)
{
    animator *animator_plus_sound;
    animation *default_plus_sound;
    animation *hover_plus_sound;
    animation *click_plus_sound;
    sprite_set_fixed_origin(plus_sound, (sfVector2f){99, 31});
    sprite_set_pos(plus_sound, (sfVector2f){980, 710});
    animator_plus_sound = new_animator(plus_sound);
    default_plus_sound = new_animation("default_plus_sound",
    NULL, true, 10);
    animation_add_frame(default_plus_sound, (sfIntRect){0, 0, 68, 61});
    animator_add_animation(animator_plus_sound, default_plus_sound);
    animator_set_default(animator_plus_sound, "default_plus_sound");
    hover_plus_sound = new_animation("hover_plus_sound", NULL, false, 10);
    animation_add_frame(hover_plus_sound, (sfIntRect){0, 61, 68, 61});
    animator_add_animation(animator_plus_sound, hover_plus_sound);
    click_plus_sound = new_animation("click_plus_sound", NULL, false, 10);
    animation_add_frame(click_plus_sound, (sfIntRect){0, 122, 68, 61});
    animator_add_animation(animator_plus_sound, click_plus_sound);
    sprite_add_event_update_function(plus_sound, button_click_plus_sound);
    sprite_add_clock_update_function(plus_sound, button_hover_plus_sound);
}
