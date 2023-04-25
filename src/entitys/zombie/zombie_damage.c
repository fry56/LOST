/*
** EPITECH PROJECT, 2023
** zombie_damage.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <zombie/zombie.h>
#include <entity_sounds.h>
#include <zombie/zombie_sounds_config.h>
#include <particles/particles.h>
#include <map/map.h>
#include <stdlib.h>
#include <survivor/survivor.h>

static void zombie_death(sprite *sprite_datas, zombie_s *zombie_datas)
{
    float angle = sfSprite_getRotation(sprite_datas->sf_sprite);
    float rand_angle = rand() % 20;
    survivor_s *survivor_datas =
            ((map_s *)sprite_datas->host->datas)->survivor_entity->datas;

    sound_manager_play_sound(zombie_datas->sound_mgr,
        get_random_sound_by_type(zombie_sound_config,sound_death).name);
    zombie_datas->status = death;
    animator_play_animation(sprite_datas->animator,
        get_zombie_anim_by_type(zombie_datas, anim_death).name);
    box_collider_destroy(zombie_datas->box_collider);
    sfSprite_setRotation(sprite_datas->sf_sprite,
        angle + (rand() % 100 > 50 ? angle - rand_angle : angle + rand_angle));
    survivor_datas->xp++;
}

void zombie_damage(sprite *sprite_datas, uint16_t amount)
{
    zombie_s *zombie_datas = sprite_datas->datas;

    if (zombie_datas->status == death)
        return;
    zombie_datas->health -= amount;
    sound_manager_play_sound(zombie_datas->sound_mgr,
        get_random_sound_by_type(zombie_sound_config, sound_damage).name);
    new_particles(sprite_datas->host, sprite_datas->pos, thashmap_get(
        sprite_datas->host->host->map_datas, "particles_blood")->value);
    if (zombie_datas->health <= 0)
        zombie_death(sprite_datas, zombie_datas);
    zombie_set_trigger(sprite_datas);
}
