/*
** EPITECH PROJECT, 2023
** get_eombie_anim_by_type.c
** File description:
** desc
*/

#include <entity_animations.h>
#include <zombie/zombie.h>

entity_animation_s get_zombie_anim_by_type(zombie_s *zombie_datas,
    entity_animation_type_e type)
{
    zombie_animator_s animator =
        zombies_animator_config[zombie_datas->type];
    entity_animation_s temp_anim;

    for (int i = 0; i < animator.nbr_animations; ++i) {
        temp_anim = animator.list_animations[i];
        if (temp_anim.type == type)
            return temp_anim;
    }
    return animator.list_animations[0];
}
