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

static void button_save_hover(sprite *data, sfClock *clock UNUSED)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_over(data, &data->host->host->event))
        return;
    animator_play_animation(animator_data, "save_quit_hover");
}

static void button_save_click(sprite *data, window *window_datas)
{
    animator *animator_data = data->animator;
    survivor_s *survivor_datas;
    if (window_datas->event.type != sfEvtMouseButtonPressed)
        return;
    if (!sprite_is_mouse_click(data, &window_datas->event))
        return;
    survivor_datas = thashmap_get(
        data->host->host->map_datas, "SURVIVOR_DATAS")->value;
    animator_play_animation(animator_data, "save_quit_click");
    survivor_save(survivor_datas);
}

void init_save_pause_button(sprite *quit_button)
{
    animator *save_pause_animator;
    animation *save_pause_default;
    animation *save_hover;
    animation *save_click;
    sprite_set_fixed_origin(quit_button, (sfVector2f){43, 33});
    sprite_set_pos(quit_button, (sfVector2f){184, 730});
    save_pause_animator = new_animator(quit_button);
    save_pause_default = new_animation("save_quit_default",
        NULL, true, 10);
    animation_add_frame(save_pause_default, (sfIntRect){0, 0, 87, 32});
    animator_add_animation(save_pause_animator, save_pause_default);
    animator_set_default(save_pause_animator, "save_quit_default");
    save_hover = new_animation("save_quit_hover", NULL, false, 10);
    animation_add_frame(save_hover, (sfIntRect){0, 33,  87, 32});
    animator_add_animation(save_pause_animator, save_hover);
    save_click = new_animation("save_quit_click", NULL, false, 10);
    animation_add_frame(save_click, (sfIntRect){0, 66,  87, 32});
    animator_add_animation(save_pause_animator, save_click);
    sprite_add_event_update_function(quit_button, button_save_click);
    sprite_add_clock_update_function(quit_button, button_save_hover);
}
