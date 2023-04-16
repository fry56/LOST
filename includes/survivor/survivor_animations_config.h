/*
** EPITECH PROJECT, 2023
** animation_config.h
** File description:
** desc
*/
#ifndef animations_config
    #define animations_config

    #include "weapon/weapon.h"
    #include "entity_animations.h"
    #include "survivor/survivor_animations.h"

    static survivor_animator_s survivor_animator_config[] UNUSED = {
        {weapon_knife, 3, {
            {
                anim_idle,
                "anim_survivor_idle_knife",
                "assets/sprites/characters/survivor"
                "/knife/survivor-idle_knife.png",
                20,
                20,
                {1, 1, 289, 224},
                true,
                false,
                true,
                {105.0f, 112.0f},
                8.0f
            },
            {
                anim_melee,
                "anim_survivor_melee_knife",
                "assets/sprites/characters/survivor"
                "/knife/survivor-melee_knife.png",
                15,
                15,
                {1, 1, 329, 300},
                false,
                false,
                true,
                {105.0f, 112.0f},
                2
            },
            {
                anim_move,
                "anim_survivor_move_knife",
                "assets/sprites/characters/survivor"
                "/knife/survivor-move_knife.png",
                20,
                20,
                {1, 1, 279, 2019},
                true,
                false,
                true,
                {105.0f, 112.0f},
                3.0f
            },
        }},
        {weapon_handgun, 5, {
            {
                anim_idle,
                "anim_survivor_idle_handgun",
                "assets/sprites/characters/survivor"
                "/handgun/survivor-idle_handgun.png",
                20,
                20,
                {1, 1, 253, 216},
                true,
                false,
                true,
                {105.0f, 112.0f},
                8.0f
            },
            {
                anim_melee,
                "anim_survivor_melee_handgun",
                "assets/sprites/characters/survivor"
                "/handgun/survivor-melee_handgun.png",
                15,
                15,
                {1, 1, 291, 256},
                false,
                false,
                true,
                {105.0f, 112.0f},
                3.5f
            },
            {
                anim_move,
                "anim_survivor_move_handgun",
                "assets/sprites/characters/survivor"
                "/handgun/survivor-move_handgun.png",
                20,
                20,
                {1, 1, 258, 220},
                true,
                false,
                true,
                {105.0f, 112.0f},
                3.0f
            },
            {
                anim_reload,
                "anim_survivor_reload_handgun",
                "assets/sprites/characters/survivor"
                "/handgun/survivor-reload_handgun.png",
                15,
                15,
                {1, 1, 260, 230},
                false,
                false,
                true,
                {105.0f, 112.0f},
                5.0f
            },
            {
                anim_shoot,
                "anim_survivor_shoot_handgun",
                "assets/sprites/characters/survivor"
                "/handgun/survivor-shoot_handgun.png",
                3,
                3,
                {1, 1, 255, 215},
                false,
                false,
                true,
                {105.0f, 112.0f},
                1.0f
            }
        }},
        {weapon_rifle, 5, {
            {
                anim_idle,
                "anim_survivor_idle_rifle",
                "assets/sprites/characters/survivor"
                "/rifle/survivor-idle_rifle.png",
                20,
                20,
                {1, 1, 313, 207},
                true,
                false,
                true,
                {105.0f, 112.0f},
                8.0f
            },
            {
                anim_melee,
                "anim_survivor_melee_rifle",
                "assets/sprites/characters/survivor"
                "/rifle/survivor-melee_rifle.png",
                15,
                15,
                {1, 1, 358, 353},
                false,
                false,
                true,
                {114, 201},
                3.5f
            },
            {
                anim_move,
                "anim_survivor_move_rifle",
                "assets/sprites/characters/survivor"
                "/rifle/survivor-move_rifle.png",
                20,
                20,
                {1, 1, 313, 206},
                true,
                false,
                true,
                {105.0f, 112.0f},
                3.0f
            },
            {
                anim_reload,
                "anim_survivor_reload_rifle",
                "assets/sprites/characters/survivor"
                "/rifle/survivor-reload_rifle.png",
                20,
                20,
                {1, 1, 322, 217},
                false,
                false,
                true,
                {105.0f, 112.0f},
                5.0f
            },
            {
                anim_shoot,
                "anim_survivor_shoot_rifle",
                "assets/sprites/characters/survivor"
                "/rifle/survivor-shoot_rifle.png",
                3,
                3,
                {1, 1, 312, 206},
                false,
                false,
                true,
                {105.0f, 112.0f},
                2.0f
            }
        }},
        {weapon_shotgun, 5, {
            {
                anim_idle,
                "anim_survivor_idle_shotgun",
                "assets/sprites/characters/survivor"
                "/shotgun/survivor-idle_shotgun.png",
                20,
                20,
                {1, 1, 313, 207},
                true,
                false,
                true,
                {105.0f, 112.0f},
                8.0f
            },
            {
                anim_melee,
                "anim_survivor_melee_shotgun",
                "assets/sprites/characters/survivor"
                "/shotgun/survivor-melee_shotgun.png",
                15,
                15,
                {1, 1, 358, 353},
                false,
                false,
                true,
                {114, 201},
                3.5f
            },
            {
                anim_move,
                "anim_survivor_move_shotgun",
                "assets/sprites/characters/survivor"
                "/shotgun/survivor-move_shotgun.png",
                20,
                20,
                {1, 1, 313, 206},
                true,
                false,
                true,
                {105.0f, 112.0f},
                3.0f
            },
            {
                anim_reload,
                "anim_survivor_reload_shotgun",
                "assets/sprites/characters/survivor"
                "/shotgun/survivor-reload_shotgun.png",
                15,
                15,
                {1, 1, 322, 217},
                false,
                false,
                true,
                {105.0f, 112.0f},
                5.0f
            },
            {
                anim_shoot,
                "anim_survivor_shoot_shotgun",
                "assets/sprites/characters/survivor"
                "/shotgun/survivor-shoot_shotgun.png",
                3,
                3,
                {1, 1, 312, 206},
                false,
                false,
                true,
                {105.0f, 112.0f},
                2.0f
            }
        }},
    };

#endif //animation_config
