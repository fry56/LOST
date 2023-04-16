/*
** EPITECH PROJECT, 2023
** survivor_animations.h
** File description:
** desc
*/
#ifndef survivor_animations
    #define survivor_animations

    #include <entity_animations.h>
    #include <survivor/weapon/weapon.h>

    typedef struct survivor_animator_t {
        weapons_type_e type;
        uint8_t nbr_animations;
        entity_animation_s list_animations[5];
    } survivor_animator_s;

#endif //survivor_animations
