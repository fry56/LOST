/*
** EPITECH PROJECT, 2023
** get_animation_by_type.c
** File description:
** desc
*/

#include <entity_animations.h>
#include <survivor/survivor.h>

entity_animation_s get_survivor_anim_by_type(survivor_s *survivor_datas,
    entity_animation_type_e type)
{
    survivor_animator_s animator =
        survivor_animator_config[survivor_datas->weapon_mgr->equiped_weapon];
    entity_animation_s temp_anim;

    for (int i = 0; i < animator.nbr_animations; ++i) {
        temp_anim = animator.list_animations[i];
        if (temp_anim.type == type)
            return temp_anim;
    }
    return animator.list_animations[0];
}
