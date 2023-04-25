/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-jules.danet
** File description:
** 1920x1080.c
*/

#include <t_ctype.h>
#include "survivor/survivor.h"
#include <functions.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>
#include "t_string.h"

static void button_hover_1920(sprite *data, sfClock *clock UNUSED)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_over(data, &data->host->host->event))
        return;
    animator_play_animation(animator_data, "hover_1920");
}

static void button_click_1920(sprite *data, window *window_datas)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_click(data, &window_datas->event))
        return;
    animator_play_animation(animator_data, "click_1920");
    sfRenderWindow_setSize(window_datas->window, (sfVector2u){1920, 1080});

}

void init_1920x1080_button(sprite *button_1920_1080)
{
    animator *animator_1920;
    animation *default_1920;
    animation *hover_1920;
    animation *click_1920;
    sprite_set_fixed_origin(button_1920_1080, (sfVector2f){99, 31});
    sprite_set_pos(button_1920_1080, (sfVector2f){630, 495});
    animator_1920 = new_animator(button_1920_1080);
    default_1920 = new_animation("default_1920",
    NULL, true, 10);
    animation_add_frame(default_1920, (sfIntRect){0, 0, 192, 32});
    animator_add_animation(animator_1920, default_1920);
    animator_set_default(animator_1920, "default_1920");
    hover_1920 = new_animation("hover_1920", NULL, false, 10);
    animation_add_frame(hover_1920, (sfIntRect){0, 32, 192, 32});
    animator_add_animation(animator_1920, hover_1920);
    click_1920 = new_animation("click_1920", NULL, false, 10);
    animation_add_frame(click_1920, (sfIntRect){0, 64, 192, 32});
    animator_add_animation(animator_1920, click_1920);
    sprite_add_event_update_function(button_1920_1080, button_click_1920);
    sprite_add_clock_update_function(button_1920_1080, button_hover_1920);
}
