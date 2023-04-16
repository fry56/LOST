/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-jules.danet
** File description:
** init_main_menu.c
*/

#include <t_ctype.h>
#include "survivor/survivor.h"
#include <functions.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>

void init_main_menu(scene *main_menu)
{
    sprite *background = new_sprite(main_menu,
    "assets/sprites/main_menu/background.png", 1);
    sprite_set_pos(background, (sfVector2f){1920 / 2, 1080 / 2});
    sprite *new_game = new_sprite(main_menu,
    "assets/sprites/main_menu/new_game_button.png", 1);
    init_new_game_button(new_game);
    sprite *continue_button = new_sprite(main_menu,
    "assets/sprites/main_menu/continue_button.png", 1);
    init_continue_button(continue_button);
    sprite *settings_button = new_sprite(main_menu,
    "assets/sprites/main_menu/settings_button.png", 1);
    init_settings_button(settings_button);
    sprite *quit_button = new_sprite(main_menu,
    "assets/sprites/main_menu/quit_button.png", 1);
    init_quit_button(quit_button);
}
