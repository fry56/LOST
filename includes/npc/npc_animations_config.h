/*
** EPITECH PROJECT, 2023
** npc_animations_config.h
** File description:
** desc
*/
#ifndef npc_animations_config_h
    #define npc_animations_config_h

    #include <entity_animations.h>

    static entity_animation_s npc_animations_config[] UNUSED = {
        {
            anim_idle,
            "anim_npc_idle",
            "assets/sprites/characters/npc/npc_idle.png",
            8,
            8,
            {1, 1, 512, 512},
            true,
            false,
            true,
            {280, 125},
            15.0f
        },
        {
            anim_idle,
            NULL,
            NULL,
            0,
            0,
            {0, 0, 0, 0},
            false,
            false,
            false,
            {0, 0},
            0.0f
        }
    };

#endif //npc_animations_config
