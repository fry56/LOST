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

void zombie_damage(sprite *sprite_datas, uint16_t amount)
{
    zombie_s *zombie_datas = sprite_datas->datas;

    if (zombie_datas->status == death)
        return;
    zombie_datas->health -= amount;
    printf("Zombie health : %d \n", zombie_datas->health);
    sound_manager_play_sound(zombie_datas->sound_mgr,
        get_random_sound_by_type(zombie_sound_config, sound_damage).name);
    new_particles(sprite_datas->host, sprite_datas->pos, thashmap_get(
        sprite_datas->host->host->map_datas, "particles_blood")->value);
    if (zombie_datas->health <= 0) {
        sound_manager_play_sound(zombie_datas->sound_mgr,
            get_random_sound_by_type(zombie_sound_config,
            sound_death).name);
        zombie_datas->status = death;
        animator_play_animation(sprite_datas->animator,
            get_zombie_anim_by_type(zombie_datas, anim_death).name);
        box_collider_destroy(zombie_datas->box_collider);
    } else
        zombie_set_trigger(sprite_datas);
}
