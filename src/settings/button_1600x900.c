/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-jules.danet
** File description:
** 1600x900.c
*/

#include <t_ctype.h>
#include "survivor/survivor.h"
#include <functions.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>
#include "t_string.h"

static void button_hover_1600(sprite *data, sfClock *clock UNUSED)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_over(data, &data->host->host->event))
        return;
    animator_play_animation(animator_data, "hover_1600");
}

static void button_click_1600(sprite *data, window *window_datas)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_click(data, &window_datas->event))
        return;
    animator_play_animation(animator_data, "click_1600");
    sfRenderWindow_setSize(window_datas->window, (sfVector2u){1600, 900});
}

void init_1600x900_button(sprite *button_1600_900)
{
    animator *animator_1600;
    animation *default_1600;
    animation *hover_1600;
    animation *click_1600;
    sprite_set_fixed_origin(button_1600_900, (sfVector2f){99, 31});
    sprite_set_pos(button_1600_900, (sfVector2f){880, 495});
    animator_1600 = new_animator(button_1600_900);
    default_1600 = new_animation("default_1600",
    NULL, true, 10);
    animation_add_frame(default_1600, (sfIntRect){0, 0, 192, 32});
    animator_add_animation(animator_1600, default_1600);
    animator_set_default(animator_1600, "default_1600");
    hover_1600 = new_animation("hover_1600", NULL, false, 10);
    animation_add_frame(hover_1600, (sfIntRect){0, 32, 192, 32});
    animator_add_animation(animator_1600, hover_1600);
    click_1600 = new_animation("click_1600", NULL, false, 10);
    animation_add_frame(click_1600, (sfIntRect){0, 64, 192, 32});
    animator_add_animation(animator_1600, click_1600);
    sprite_add_event_update_function(button_1600_900, button_click_1600);
    sprite_add_clock_update_function(button_1600_900, button_hover_1600);
}
