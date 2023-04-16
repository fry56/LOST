/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-jules.danet
** File description:
** new_game_button.c
*/

#include <t_ctype.h>
#include "survivor/survivor.h"
#include <functions.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>

static void button_new_game_hover(sprite *data, sfClock *clock UNUSED)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_over(data, &data->host->host->event))
        return;
    animator_play_animation(animator_data, "anim_new_game_hover");
}

static void button_new_game_click(sprite *data, window *window_datas)
{
    animator *animator_data = data->animator;
    t_hashmap_node *default_scene_node;

    if (!sprite_is_mouse_click(data, &window_datas->event))
        return;
    default_scene_node = thashmap_get(window_datas->map_datas,
        "default_game_scene");
    animator_play_animation(animator_data, "anim_new_game_click");
    window_change_scene(window_datas, default_scene_node->value);
}

void init_new_game_button(sprite *new_game)
{
    animator *new_game_animator;
    animation *new_game_default;
    animation *new_game_hover;
    animation *new_game_click;
    sprite_set_fixed_origin(new_game, (sfVector2f){99, 31});
    sprite_set_pos(new_game, (sfVector2f){225, 400});
    new_game_animator = new_animator(new_game);
    new_game_default = new_animation("anim_new_game_default", NULL, true, 10);
    animation_add_frame(new_game_default, (sfIntRect){0, 0, 199, 31});
    animator_add_animation(new_game_animator, new_game_default);
    animator_set_default(new_game_animator, "anim_new_game_default");
    new_game_hover = new_animation("anim_new_game_hover", NULL, false, 10);
    animation_add_frame(new_game_hover, (sfIntRect){0, 31, 199, 31});
    animator_add_animation(new_game_animator, new_game_hover);
    new_game_click = new_animation("anim_new_game_click", NULL, false, 10);
    animation_add_frame(new_game_click, (sfIntRect){0, 62, 199, 31});
    animator_add_animation(new_game_animator, new_game_click);
    sprite_add_event_update_function(new_game, button_new_game_click);
    sprite_add_clock_update_function(new_game, button_new_game_hover);
}
