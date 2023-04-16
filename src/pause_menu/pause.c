/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-jules.danet
** File description:
** pause_menu.c
*/

#include <t_ctype.h>
#include "survivor/survivor.h"
#include <functions.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>
#include "t_string.h"
#include "t_hashmap.h"

void init_pause_menu(scene *pause_menu)
{
    sprite *background = new_sprite(pause_menu,
    "assets/sprites/pause_menu/pause_menu.png", 1);
    sprite_set_pos(background, (sfVector2f){1920 / 2, 1080 / 2});
    sprite *settings_button = new_sprite(pause_menu,
    "assets/sprites/pause_menu/settings_pause_button.png", 1);
    init_settings_pause_button(settings_button);
    sprite *quit_button = new_sprite(pause_menu,
    "assets/sprites/pause_menu/quit_pause_button.png", 1);
    init_quit_pause_button(quit_button);
}

void go_pause_menu(UNUSED scene *data, window *window_datas)
{
    t_hashmap_node *scene = thashmap_get(window_datas->map_datas,
    "prev_scene");
    if (window_datas->event.type != sfEvtKeyPressed ||
    window_datas->event.key.code != sfKeyEscape)
        return;
    window_change_scene(window_datas, "pause_menu");
    scene->value = "pause_menu";
}

void pause_to_game(UNUSED scene *data, window *window_datas)
{
    if (window_datas->event.type != sfEvtKeyPressed ||
    window_datas->event.key.code != sfKeyEscape)
        return;
    window_change_scene(window_datas, "game");
}

void settings_to_pause(window *window_datas)
{
    if (window_datas->event.type != sfEvtKeyPressed ||
    window_datas->event.key.code != sfKeyEscape)
        return;
    window_change_scene(window_datas, "pause_menu");
}
