/*
** EPITECH PROJECT, 2023
** zombie_set_trigger.c
** File description:
** desc
*/

#include <zombie/zombie.h>
#include <zombie/zombie_sounds_config.h>
#include <entity_sounds.h>
#include <survivor/survivor.h>
#include <map/map.h>

void zombie_set_trigger(sprite *sprite_datas)
{
    zombie_s *zombie_datas = sprite_datas->datas;
    sprite *survivor_data =
        ((map_s *)sprite_datas->host->datas)->survivor_entity;

    if (zombie_datas->status == death || zombie_datas->status == trigger)
        return;
    zombie_datas->status = trigger;
    sound_manager_play_sound(zombie_datas->sound_mgr,
        get_random_sound_by_type(zombie_sound_config, sound_trigger).name);
    update_zombie_path(survivor_data, survivor_data->datas);
}

void zombie_set_idle(sprite *sprite_datas)
{
    zombie_s *zombie_datas = sprite_datas->datas;

    if (zombie_datas->status == death || zombie_datas->status == idle)
        return;
    zombie_datas->status = idle;
}
