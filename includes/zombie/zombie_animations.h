/*
** EPITECH PROJECT, 2023
** zombie_animations.h
** File description:
** desc
*/
#ifndef zombie_animations
    #define zombie_animations

    #include <entity_animations.h>

    typedef struct zombie_animator_t {
        uint8_t nbr_animations;
        entity_animation_s list_animations[4];
    } zombie_animator_s;

#endif //zombie_animations
