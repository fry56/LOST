/*
** EPITECH PROJECT, 2023
** particles_config.h
** File description:
** desc
*/
#ifndef particles_config
    #define particles_config

    #include <entity_animations.h>

    static entity_animation_s particles_animation_config[] UNUSED = {
        {
            anim_particles,
            "particles_blood",
            "assets/sprites/particles/blood/blood_1.png",
            24,
            6,
            {1, 1, 100, 100},
            false,
            false,
            false,
            {0,0},
            0.5f
        },
        {
            unknown,
            NULL,
            NULL,
            0,
            0,
            {0, 0, 0, 0},
            false,
            false,
            false,
            {0,0},
            0
        }
    };

#endif //particles_config
