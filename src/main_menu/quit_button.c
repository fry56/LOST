/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-jules.danet
** File description:
** quit_button.c
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
    animator_play_animation(animator_data, "anim_quit_hover");
}

static void button_quit_click(sprite *data, window *window_datas)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_click(data, &window_datas->event))
        return;
    animator_play_animation(animator_data, "anim_quit_click");
    sfMusic_destroy(data->host->datas);
    sfRenderWindow_close(window_datas->window);
}

void init_quit_button(sprite *quit_button)
{
    animator *quit_animator;
    animation *quit_default;
    animation *quit_hover;
    animation *quit_click;
    sprite_set_fixed_origin(quit_button, (sfVector2f){99, 33});
    sprite_set_pos(quit_button, (sfVector2f){225, 675});
    quit_animator = new_animator(quit_button);
    quit_default = new_animation("anim_quit_default", NULL, true, 10);
    animation_add_frame(quit_default, (sfIntRect){0, 0, 199, 33});
    animator_add_animation(quit_animator, quit_default);
    animator_set_default(quit_animator, "anim_quit_default");
    quit_hover = new_animation("anim_quit_hover", NULL, false, 10);
    animation_add_frame(quit_hover, (sfIntRect){0, 33, 199, 33});
    animator_add_animation(quit_animator, quit_hover);
    quit_click = new_animation("anim_quit_click", NULL, false, 10);
    animation_add_frame(quit_click, (sfIntRect){0, 66, 199, 33});
    animator_add_animation(quit_animator, quit_click);
    sprite_add_event_update_function(quit_button, button_quit_click);
    sprite_add_clock_update_function(quit_button, button_quit_hover);
}
