/*
** EPITECH PROJECT, 2023
** zombie_init_animations.c
** File description:
** desc
*/

#include <zombie/zombie_animations_config.h>
#include "Class/t_sprite.h"
#include "zombie/zombie.h"
#include "entity_animations.h"

void zombie_init_animations(scene *scene_datas, sprite *new_zombie)
{
    entity_animation_s tmp_anim_conf;
    animator *survivor_animator = new_animator(new_zombie);
    entity_animation_s actual_survivor_anim;

    for (int i = 0; i < NBR_ZOMBIES_TYPES; ++i) {
        for (int j = 0; j < zombies_animator_config[i].nbr_animations; ++j) {
            tmp_anim_conf = zombies_animator_config[i].list_animations[j];
            animator_add_animation(survivor_animator, thashmap_get(scene_datas->
                host->map_datas,tmp_anim_conf.name)->value);
        }
    }
    actual_survivor_anim = get_zombie_anim_by_type((zombie_s *)new_zombie->
        datas, anim_idle);
    animator_play_animation(survivor_animator, actual_survivor_anim.name);
}
