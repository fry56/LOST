/*
** EPITECH PROJECT, 2023
** survivor_weapon_reload.c
** File description:
** desc
*/

#include "Class/t_window.h"
#include "Class/t_sprite.h"
#include "survivor/survivor.h"
#include "survivor/survivor_animations_config.h"

void survivor_event_weapon_reload(sprite *sprite_datas, window *window_datas)
{
    uint64_t timestamp;

    if (window_datas->event.key.code != sfKeyR ||
        window_datas->event.type != sfEvtKeyPressed)
        return;
    if (((survivor_s *)sprite_datas->datas)->freeze)
        return;
    timestamp = sfClock_getElapsedTime(window_datas->global_clock).microseconds;
    if (((survivor_s *)sprite_datas->datas)->weapon_mgr->timestamp_wait >
        timestamp)
        return;
    weapon_reload(sprite_datas, timestamp);
}
