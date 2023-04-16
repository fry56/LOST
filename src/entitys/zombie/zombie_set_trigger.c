/*
** EPITECH PROJECT, 2023
** zombie_set_trigger.c
** File description:
** desc
*/

#include <zombie/zombie.h>
#include <zombie/zombie_sounds_config.h>
#include <entity_sounds.h>

void zombie_set_trigger(sprite *sprite_datas)
{
    zombie_s *zombie_datas = sprite_datas->datas;

    if (zombie_datas->status == death || zombie_datas->status == trigger)
        return;
    zombie_datas->status = trigger;
    sound_manager_play_sound(zombie_datas->sound_mgr,
        get_random_sound_by_type(zombie_sound_config, sound_trigger).name);
}
