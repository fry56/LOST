/*
** EPITECH PROJECT, 2022
** set_origin_center.c
** File description:
** desc
*/

#include "Class/t_sprite.h"

void sprite_set_origin_center(sprite *self)
{
    sfFloatRect sprite_bounds = sfSprite_getGlobalBounds(self->sf_sprite);
    sfSprite_setOrigin(self->sf_sprite
        , (sfVector2f){(sprite_bounds.width / 2), (sprite_bounds.height / 2)});
}
