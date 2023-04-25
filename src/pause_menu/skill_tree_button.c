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

static void button_skill_tree_hover(sprite *data, sfClock *clock UNUSED)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_over(data, &data->host->host->event))
        return;
    animator_play_animation(animator_data, "skill_tree_quit_hover");
}

static void button_skill_tree_click(sprite *data, window *window_datas)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_click(data, &window_datas->event))
        return;
    animator_play_animation(animator_data, "skill_tree_quit_click");
    window_change_scene(window_datas, "skill_tree");
    skill_tree_update(window_datas->actual_scene->value);
}

void init_skill_tree_pause_button(sprite *quit_button)
{
    animator *skill_tree_pause_animator;
    animation *skill_tree_pause_default;
    animation *skill_tree_hover;
    animation *skill_tree_click;
    sprite_set_fixed_origin(quit_button, (sfVector2f){124, 35});
    sprite_set_pos(quit_button, (sfVector2f){265, 345});
    skill_tree_pause_animator = new_animator(quit_button);
    skill_tree_pause_default = new_animation("skill_tree_quit_default",
        NULL, true, 10);
    animation_add_frame(skill_tree_pause_default, (sfIntRect){0, 0, 248, 33});
    animator_add_animation(skill_tree_pause_animator, skill_tree_pause_default);
    animator_set_default(skill_tree_pause_animator, "skill_tree_quit_default");
    skill_tree_hover = new_animation("skill_tree_quit_hover", NULL, false, 10);
    animation_add_frame(skill_tree_hover, (sfIntRect){0, 33, 248, 34});
    animator_add_animation(skill_tree_pause_animator, skill_tree_hover);
    skill_tree_click = new_animation("skill_tree_quit_click", NULL, false, 10);
    animation_add_frame(skill_tree_click, (sfIntRect){0, 68, 248, 33});
    animator_add_animation(skill_tree_pause_animator, skill_tree_click);
    sprite_add_event_update_function(quit_button, button_skill_tree_click);
    sprite_add_clock_update_function(quit_button, button_skill_tree_hover);
}
