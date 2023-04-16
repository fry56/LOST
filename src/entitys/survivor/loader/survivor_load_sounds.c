/*
** EPITECH PROJECT, 2023
** load_survivor_sounds.c
** File description:
** desc
*/

#include "Class/t_window.h"
#include "Class/t_sound_manager.h"
#include "survivor/survivor_sounds_config.h"
#include <t_printf.h>

void survivor_load_sounds(window *window_datas)
{
    sound *temp;

    for (int i = 0; survivor_sound_config[i].name != NULL ; ++i) {
        temp = new_sound(survivor_sound_config[i].name,
            survivor_sound_config[i].path,
            survivor_sound_config[i].min_dist,
            survivor_sound_config[i].volume);
        temp->loop = survivor_sound_config[i].loop;
        temp->over_play = survivor_sound_config[i].over_play;
        thashmap_add(window_datas->map_datas, survivor_sound_config[i].name,
            temp);
        tprintf("[SOUND] %s - Loaded\n", survivor_sound_config[i].name);
    }
}
