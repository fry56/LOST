/*
** EPITECH PROJECT, 2023
** survivor_event_space.c
** File description:
** desc
*/

#include "Class/t_window.h"
#include "Class/t_sprite.h"
#include "survivor/survivor.h"
#include "survivor/survivor_animations_config.h"
#include <npc/npc.h>

void survivor_event_space(sprite *sprite_datas, window *window_datas)
{
    uint64_t timestamp;
    weapons_manager_s *weapon_mgr =
            ((survivor_s *)sprite_datas->datas)->weapon_mgr;

    if (window_datas->event.key.code != sfKeySpace ||
        window_datas->event.type != sfEvtKeyPressed)
        return;
    if (((survivor_s *)sprite_datas->datas)->freeze) {
        npc_event_next_dialogue(sprite_datas,
            ((survivor_s *)sprite_datas->datas)->npc_dialogue);
        return;
    }
    timestamp = sfClock_getElapsedTime(window_datas->global_clock).microseconds;
    if (weapon_mgr->weapons[weapon_mgr->equiped_weapon].melee > timestamp)
        return;
    weapon_melee(sprite_datas, timestamp);
}
