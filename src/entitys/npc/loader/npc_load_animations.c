/*
** EPITECH PROJECT, 2023
** npc_load_animations.c
** File description:
** desc
*/

#include "Class/t_window.h"
#include "Class/t_sprite_animator.h"
#include <npc/npc.h>

void npc_load_animations(window *window_datas)
{
    for (int i = 0; npc_animations_config[i].name != NULL; ++i)
        entitys_load_animations(window_datas, npc_animations_config[i]);
}
