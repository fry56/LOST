/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-jules.danet
** File description:
** continue_button.c
*/

#include <t_ctype.h>
#include "survivor/survivor.h"
#include <functions.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>

static void button_continue_hover(sprite *data, sfClock *clock UNUSED)
{
    animator *animator_data = data->animator;

    if (!survivor_have_save())
        return;
    if (!sprite_is_mouse_over(data, &data->host->host->event))
        return;
    animator_play_animation(animator_data, "anim_continue_hover");
}

static void button_continue_click(sprite *data, window *window_datas)
{
    animator *animator_data = data->animator;
    survivor_s *survivor_datas;
    t_hashmap_node *default_scene_node;

    if (!sprite_is_mouse_click(data, &window_datas->event))
        return;
    if (!survivor_have_save())
        return;
    sfMusic_destroy(data->host->datas);
    animator_play_animation(animator_data, "anim_continue_click");
    survivor_datas = thashmap_get(
        data->host->host->map_datas, "SURVIVOR_DATAS")->value;
    default_scene_node = thashmap_get(window_datas->map_datas,
        "default_game_scene");
    survivor_load_save(survivor_datas);
    window_change_scene(window_datas, default_scene_node->value);
}

void init_continue_button(sprite *continue_button)
{
    animator *continue_animator;
    animation *continue_default;
    animation *continue_hover;
    animation *continue_click;
    sprite_set_fixed_origin(continue_button, (sfVector2f){99, 31});
    sprite_set_pos(continue_button, (sfVector2f){225, 475});
    continue_animator = new_animator(continue_button);
    continue_default = new_animation("anim_continue_default", NULL, true, 10);
    animation_add_frame(continue_default, (sfIntRect){0, 0, 189, 31});
    animator_add_animation(continue_animator, continue_default);
    animator_set_default(continue_animator, "anim_continue_default");
    continue_hover = new_animation("anim_continue_hover", NULL, false, 10);
    animation_add_frame(continue_hover, (sfIntRect){0, 31, 189, 31});
    animator_add_animation(continue_animator, continue_hover);
    continue_click = new_animation("anim_continue_click", NULL, false, 10);
    animation_add_frame(continue_click, (sfIntRect){0, 62, 189, 31});
    animator_add_animation(continue_animator, continue_click);
    sprite_add_event_update_function(continue_button, button_continue_click);
    sprite_add_clock_update_function(continue_button, button_continue_hover);
}
