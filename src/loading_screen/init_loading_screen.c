/*
** EPITECH PROJECT, 2023
** init_loading_screen.c
** File description:
** desc
*/

#include "survivor/survivor.h"
#include <functions.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>
#include <zombie/zombie.h>
#include <npc/npc.h>
#include <particles/particles.h>
#include <map/map.h>
#include "t_hashmap.h"

void loading_assets(scene *scene_data, sfClock *clock UNUSED)
{
    if (sfClock_getElapsedTime(clock).microseconds < 1000000)
        return;
    survivor_load_sounds(scene_data->host);
    survivor_load_animations(scene_data->host);
    survivor_init_datas(scene_data->host);
    npc_load_animations(scene_data->host);
    zombie_load_animations(scene_data->host);
    zombie_load_sounds(scene_data->host);
    particles_load_animations(scene_data->host);
    map_load(scene_data->host);
    window_change_scene(scene_data->host, "main_menu");
}

void init_loading_screen(window *window_datas)
{
    scene *loading = new_scene(window_datas, "loading", NULL, NULL);
    sprite *background = new_sprite(loading, "assets/sprites/loading.png", 1);

    sprite_set_pos(background, (sfVector2f){1920 / 2, 1080 / 2});
    scene_add_clock_update_function(loading, loading_assets);
}
