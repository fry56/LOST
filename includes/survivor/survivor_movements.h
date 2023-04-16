/*
** EPITECH PROJECT, 2023
** survivor_movement.h
** File description:
** desc
*/
#ifndef survivor_movement
    #define survivor_movement

    typedef struct survivor_movement_t {
        sfKeyCode key;
        char *animation_name;
        sfVector2f offset;
        sfVector2f scale;
    } survivor_movement_s;

#endif //survivor_movement
