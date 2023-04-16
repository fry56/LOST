/*
** EPITECH PROJECT, 2023
** zombie_load_sounds.c
** File description:
** desc
*/

#include "Class/t_window.h"
#include "Class/t_sound_manager.h"
#include <zombie/zombie_sounds_config.h>
#include <t_printf.h>

void zombie_load_sounds(window *window_datas)
{
    sound *temp;

    for (int i = 0; zombie_sound_config[i].name != NULL ; ++i) {
        temp = new_sound(zombie_sound_config[i].name,
            zombie_sound_config[i].path,
            zombie_sound_config[i].min_dist,
            zombie_sound_config[i].volume);
        temp->loop = zombie_sound_config[i].loop;
        temp->over_play = zombie_sound_config[i].over_play;
        thashmap_add(window_datas->map_datas, zombie_sound_config[i].name,
            temp);
        tprintf("[SOUND] %s - Loaded\n", zombie_sound_config[i].name);
    }
}
