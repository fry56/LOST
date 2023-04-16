/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** desc
*/

#include "survivor/survivor.h"
#include <functions.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>
#include <zombie/zombie.h>
#include <particles/particles.h>
#include <map/map.h>
#include <utils.h>
#include <box_collider/box_collider_config.h>
#include "t_hashmap.h"

void init_scenes(window *window_datas)
{
    scene *main_menu = new_scene(window_datas, "main_menu", NULL, NULL);
    scene *game = new_scene(window_datas, "game", NULL, NULL);
    scene *settings_menu = new_scene(window_datas, "settings_menu", NULL, NULL);
    scene *pause_menu = new_scene(window_datas, "pause_menu", NULL, NULL);
    scene *commands = new_scene(window_datas, "commands", NULL, NULL);

    thashmap_add(window_datas->map_datas, "prev_scene", "game");
    scene_add_event_update_function(settings_menu, return_to_main_menu);
    scene_add_event_update_function(game, go_pause_menu);
    scene_add_event_update_function(pause_menu, pause_to_game);
    scene_add_event_update_function(commands, return_to_settings);
    init_main_menu(main_menu);
    init_settings_menu(settings_menu);
    init_pause_menu(pause_menu);
    init_commands(commands);
}

int main(void)
{
    window *window_datas = new_window("LOST", (sfVideoMode){1920, 1080, 32});

    if (!check_assets())
        return 84;
    window_datas->global_clock = sfClock_create();
    window_datas->datas = thashmap_new(256);
    sfRenderWindow_setKeyRepeatEnabled(window_datas->window, sfFalse);
    //init_scenes(window_datas);
    survivor_load_sounds(window_datas);
    survivor_load_animations(window_datas);
    survivor_init_datas(window_datas);
    zombie_load_animations(window_datas);
    zombie_load_sounds(window_datas);
    particles_load_animations(window_datas);
    map_load(window_datas);
    window_start(window_datas);
    return 0;
}
