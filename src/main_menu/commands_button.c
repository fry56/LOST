/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-jules.danet
** File description:
** commands_button.c
*/

#include <t_ctype.h>
#include "survivor/survivor.h"
#include <functions.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>
#include "t_string.h"

static void button_commands_hover(sprite *data, sfClock *clock UNUSED)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_over(data, &data->host->host->event))
        return;
    animator_play_animation(animator_data, "commands_hover");
}

static void button_commands_click(sprite *data, window *window_datas)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_click(data, &window_datas->event))
        return;
    animator_play_animation(animator_data, "commands_click");
    window_change_scene(window_datas, "commands");
}

void init_commands_button(sprite *commands_button)
{
    animator *commands_animator;
    animation *commands_default;
    animation *commands_hover;
    animation *commands_click;
    sprite_set_fixed_origin(commands_button, (sfVector2f){99, 31});
    sprite_set_pos(commands_button, (sfVector2f){240, 290});
    commands_animator = new_animator(commands_button);
    commands_default = new_animation("commands_default",
    NULL, true, 10);
    animation_add_frame(commands_default, (sfIntRect){0, 0, 194, 32});
    animator_add_animation(commands_animator, commands_default);
    animator_set_default(commands_animator, "commands_default");
    commands_hover = new_animation("commands_hover", NULL, false, 10);
    animation_add_frame(commands_hover, (sfIntRect){0, 32, 194, 32});
    animator_add_animation(commands_animator, commands_hover);
    commands_click = new_animation("commands_click", NULL, false, 10);
    animation_add_frame(commands_click, (sfIntRect){0, 64, 194, 32});
    animator_add_animation(commands_animator, commands_click);
    sprite_add_event_update_function(commands_button, button_commands_click);
    sprite_add_clock_update_function(commands_button, button_commands_hover);
}

void return_to_settings(UNUSED scene *data, window *window_datas)
{
    if (window_datas->event.type != sfEvtKeyPressed ||
    window_datas->event.key.code != sfKeyEscape)
        return;
    window_change_scene(window_datas, "settings_menu");
}

void init_commands(scene *commands)
{
    sprite *background = new_sprite(commands,
    "assets/sprites/main_menu/commands.png", 1);
    sprite_set_pos(background, (sfVector2f){1920 / 2, 1080 / 2});
}
