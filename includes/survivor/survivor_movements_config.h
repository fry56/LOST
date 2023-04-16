/*
** EPITECH PROJECT, 2023
** survivor_movements_config.h
** File description:
** desc
*/
#ifndef movements_config
    #define movements_config

    #include "survivor_movements.h"

    static survivor_movement_s survivor_movements_config[] UNUSED = {
        {sfKeyZ, "forward_move", {1, 1}, {0.5f, 0.5f}},
        {sfKeyS, "back_move", {-1, -1}, {0.5f, 0.5f}},
        {sfKeyA, "side_move", {-1, -1}, {0.5f, 0.5f}},
        {sfKeyD, "side_move", {1, 1}, {0.5f, 0.5f}},
        {sfKeyUnknown, "", {0, 0}, {0, 0}}
    };

#endif //survivor_movements_config
