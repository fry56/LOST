/*
** EPITECH PROJECT, 2023
** get_random_sound_by_type.c
** File description:
** desc
*/

#include "entity_sounds.h"
#include <stdlib.h>

entity_sound_s get_random_sound_by_type(const entity_sound_s *config,
    entity_sounds_type_e type)
{
    int random = 1 + (rand() % 3);
    int index = 0;
    entity_sound_s temp;

    while (random != 0) {
        if (config[index].type == type) {
            temp = config[index];
            random--;
        }
        if (config[index].type == sound_unknown)
            index = -1;
        index++;
    }
    return temp;
}
