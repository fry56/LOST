/*
** EPITECH PROJECT, 2023
** zombie_animations_config.h
** File description:
** desc
*/
#ifndef zombie_animations_config_h
    #define zombie_animations_config_h

    #include "zombie_animations.h"

    static zombie_animator_s zombies_animator_config[] UNUSED = {
            {4,
                {
                    {
                        anim_idle,
                        "anim_zombie_1_idle",
                        "assets/sprites/zombies/zombie_1/zombie-idle_1.png",
                        6,
                        6,
                        {1, 1, 512, 512},
                        true,
                        false,
                        true,
                        {257, 326},
                        40.0f
                    },
                    {
                        anim_move,
                        "anim_zombie_1_move",
                        "assets/sprites/zombies/zombie_1/zombie-move_1.png",
                        9,
                        9,
                        {1, 1, 512, 512},
                        true,
                        false,
                        true,
                        {257, 326},
                        8.0f
                    },
                    {
                        anim_melee,
                        "anim_zombie_1_melee",
                        "assets/sprites/zombies/zombie_1/zombie-melee_1.png",
                        9,
                        9,
                        {1, 1, 512, 512},
                        true,
                        false,
                        true,
                        {257, 326},
                        8.0f
                    },
                    {
                        anim_death,
                        "anim_zombie_1_death",
                        "assets/sprites/zombies/zombie_1/zombie-death_1.png",
                        4,
                        4,
                        {1, 1, 512, 512},
                        true,
                        true,
                        true,
                        {257, 326},
                        8.0f
                    },
                }
            }
    };

#endif //zombie_animations_config
