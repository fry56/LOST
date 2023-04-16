/*
** EPITECH PROJECT, 2023
** load_player_animation.c
** File description:
** desc
*/

#include "Class/t_window.h"
#include "survivor/survivor_animations.h"
#include "Class/t_sprite_animator.h"
#include "t_printf.h"

void entitys_load_animations(window *window_datas,
    entity_animation_s tmp_anim_conf)
{
    animation *tmp_anim;

    tmp_anim = new_animation(tmp_anim_conf.name, tmp_anim_conf.path,
        tmp_anim_conf.loop, tmp_anim_conf.frame_rate);
    animation_auto_gen_frame(tmp_anim, tmp_anim_conf.nbr_sprite,
        tmp_anim_conf.nbr_sprite_per_ligne, tmp_anim_conf.rect_start);
    tmp_anim->end_freeze = tmp_anim_conf.end_freeze;
    tmp_anim->custom_origin = tmp_anim_conf.custom_origin;
    tmp_anim->origin = tmp_anim_conf.origin;
    thashmap_add(window_datas->map_datas, tmp_anim_conf.name, tmp_anim);
    tprintf("[ANIMATION] %s - Loaded\n", tmp_anim_conf.name);
}
