/*
** EPITECH PROJECT, 2023
** zombie_event_attack.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <zombie/zombie.h>
#include <zombie/zombie_sounds_config.h>
#include <map/map.h>
#include <utils.h>
#include <stdlib.h>
#include <entity_sounds.h>

void zombie_attack_callback(sprite *sprite_datas)
{
    sprite *survivor_sprite =
        ((map_s *)sprite_datas->host->datas)->survivor_entity;

    if (get_distance(sprite_datas->pos, survivor_sprite->pos) < 100)
        survivor_damage(survivor_sprite, 10 + rand() % 20);
}

void zombie_event_attack(sprite *sprite_datas)
{
    zombie_s *zombie_datas = sprite_datas->datas;

    animator_play_animation(sprite_datas->animator,
        get_zombie_anim_by_type(sprite_datas->datas, anim_melee).name);
    sound_manager_play_sound(zombie_datas->sound_mgr,
        get_random_sound_by_type(zombie_sound_config, sound_melee).name);
}
