/*
** EPITECH PROJECT, 2023
** zombie_load_animations.c
** File description:
** desc
*/

#include "Class/t_window.h"
#include "Class/t_sprite_animator.h"
#include "t_printf.h"
#include <zombie/zombie_animations_config.h>
#include <zombie/zombie.h>

void zombie_load_animations(window *window_datas)
{
    for (int i = 0; i < NBR_ZOMBIES_TYPES; ++i)
        for (int j = 0; j < zombies_animator_config[i].nbr_animations; ++j)
            entitys_load_animations(window_datas,
                zombies_animator_config[i].list_animations[j]);
}
