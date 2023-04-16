/*
** EPITECH PROJECT, 2023
** zombie_load_animations.c
** File description:
** desc
*/

#include "Class/t_window.h"
#include "Class/t_sprite_animator.h"
#include "t_printf.h"
#include <particles/particles_config.h>

void particles_load_animations(window *window_datas)
{
    animation *tmp_anim;
    entity_animation_s tmp_anim_conf;

    for (int i = 0; particles_animation_config[i].name != NULL; ++i) {
        tmp_anim_conf = particles_animation_config[i];
        tprintf("[PARTICLES] %s - Loaded\n", tmp_anim_conf.name);
        tmp_anim = new_animation(tmp_anim_conf.name, tmp_anim_conf.path,
            tmp_anim_conf.loop, tmp_anim_conf.frame_rate);
        animation_auto_gen_frame(tmp_anim, tmp_anim_conf.nbr_sprite,
            tmp_anim_conf.nbr_sprite_per_ligne,
            tmp_anim_conf.rect_start);
        tmp_anim->end_freeze = tmp_anim_conf.end_freeze;
        thashmap_add(window_datas->map_datas, tmp_anim_conf.name, tmp_anim);
    }
}
