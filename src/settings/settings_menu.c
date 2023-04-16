/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-jules.danet
** File description:
** settings_menu.c
*/

#include <t_ctype.h>
#include "survivor/survivor.h"
#include <functions.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>
#include "t_string.h"

void init_settings_menu(scene *settings_menu)
{
    sprite *background = new_sprite(settings_menu,
    "assets/sprites/main_menu/settings_menus.png", 1);
    sprite_set_pos(background, (sfVector2f){1920 / 2, 1080 / 2});
    sprite *commands_button = new_sprite(settings_menu,
    "assets/sprites/main_menu/commands_button.png", 1);
    init_commands_button(commands_button);
}

void return_to_main_menu(UNUSED scene *data, window *window_datas)
{
    t_hashmap_node *get_scene = thashmap_get(window_datas->map_datas,
    "prev_scene");
    char *scene = get_scene->value;

    if (window_datas->event.type != sfEvtKeyPressed ||
    window_datas->event.key.code != sfKeyEscape)
        return;
    if (tstr_cmp("game", scene) == 0) {
        window_change_scene(window_datas, "main_menu");
        return;
    }
    if (tstr_cmp("pause_menu", scene) == 0)
        window_change_scene(window_datas, "pause_menu");
}
