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

static void button_quit_hover(sprite *data, sfClock *clock UNUSED)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_over(data, &data->host->host->event))
        return;
    animator_play_animation(animator_data, "pause_quit_hover");
}

static void button_quit_click(sprite *data, window *window_datas)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_click(data, &window_datas->event))
        return;
    animator_play_animation(animator_data, "pause_quit_click");
    sfRenderWindow_close(window_datas->window);
}

void init_quit_pause_button(sprite *quit_button)
{
    animator *quit_pause_animator;
    animation *quit_pause_default;
    animation *quit_pause_hover;
    animation *quit_pause_click;
    sprite_set_fixed_origin(quit_button, (sfVector2f){99, 31});
    sprite_set_pos(quit_button, (sfVector2f){240, 880});
    quit_pause_animator = new_animator(quit_button);
    quit_pause_default = new_animation("pause_quit_default",
    NULL, true, 10);
    animation_add_frame(quit_pause_default, (sfIntRect){0, 0, 170, 40});
    animator_add_animation(quit_pause_animator, quit_pause_default);
    animator_set_default(quit_pause_animator, "pause_quit_default");
    quit_pause_hover = new_animation("pause_quit_hover", NULL, false, 10);
    animation_add_frame(quit_pause_hover, (sfIntRect){0, 40, 170, 40});
    animator_add_animation(quit_pause_animator, quit_pause_hover);
    quit_pause_click = new_animation("pause_quit_click", NULL, false, 10);
    animation_add_frame(quit_pause_click, (sfIntRect){0, 80, 170, 40});
    animator_add_animation(quit_pause_animator, quit_pause_click);
    sprite_add_event_update_function(quit_button, button_quit_click);
    sprite_add_clock_update_function(quit_button, button_quit_hover);
}
