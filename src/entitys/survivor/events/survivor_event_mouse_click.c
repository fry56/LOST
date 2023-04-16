/*
** EPITECH PROJECT, 2023
** mouse_attack.c
** File description:
** desc
*/

#include "Class/t_window.h"
#include "Class/t_sprite.h"
#include "survivor/survivor.h"
#include "survivor/survivor_animations_config.h"

void survivor_event_mouse_click(sprite *sprite_datas, window *window_datas)
{
    uint64_t timestamp;

    if (window_datas->event.type != sfEvtMouseButtonPressed)
        return;
    if (((survivor_s *)sprite_datas->datas)->freeze)
        return;
    timestamp = sfClock_getElapsedTime(window_datas->global_clock).microseconds;
    if (((survivor_s *)sprite_datas->datas)->weapon_mgr->timestamp_wait >
        timestamp)
        return;
    if (((survivor_s *)sprite_datas->datas)->weapon_mgr->equiped_weapon !=
        weapon_knife)
        weapon_shoot(sprite_datas, timestamp);
    else
        weapon_melee(sprite_datas, timestamp);
}
