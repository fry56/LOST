/*
** EPITECH PROJECT, 2023
** load_player_animation.c
** File description:
** desc
*/

#include "Class/t_window.h"
#include "survivor/survivor_animations_config.h"
#include <survivor/weapon/weapon.h>
#include <entity_animations.h>

void survivor_load_animations(window *window_datas)
{
    for (int i = 0; i < NBR_WEAPONS_TYPES; ++i)
        for (int j = 0; j < survivor_animator_config[i].nbr_animations; ++j)
            entitys_load_animations(window_datas,
                survivor_animator_config[i].list_animations[j]);
}
