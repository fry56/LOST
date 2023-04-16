/*
** EPITECH PROJECT, 2023
** survivor_init_animation.c
** File description:
** desc
*/

#include "Class/t_sprite.h"
#include "survivor/survivor.h"
#include "entity_animations.h"
#include "survivor/survivor_animations_config.h"

void survivor_init_animations(scene *scene_datas, sprite *new_player)
{
    entity_animation_s tmp_anim_conf;
    animator *survivor_animator = new_animator(new_player);
    entity_animation_s actual_survivor_anim;

    for (int i = 0; i < NBR_WEAPONS_TYPES; ++i) {
        for (int j = 0; j < survivor_animator_config[i].nbr_animations; ++j) {
            tmp_anim_conf = survivor_animator_config[i].list_animations[j];
            animator_add_animation(survivor_animator, thashmap_get(scene_datas->
                host->map_datas,tmp_anim_conf.name)->value);
        }
    }
    actual_survivor_anim = get_survivor_anim_by_type((survivor_s *)new_player->
        datas, anim_idle);
    animator_play_animation(survivor_animator, actual_survivor_anim.name);
}
