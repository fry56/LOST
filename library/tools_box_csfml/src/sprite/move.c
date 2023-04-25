/*
** EPITECH PROJECT, 2022
** set_pos.c
** File description:
** desc
*/

#include "Class/t_sprite.h"
#include <SFML/Graphics.h>

void sprite_move(sprite *self, sfVector2f pos)
{
    self->pos = (sfVector2f){self->pos.x + pos.x, self->pos.y + pos.y};
    if (self->move != NULL)
        self->move(self, pos);
    sfSprite_move(self->sf_sprite, pos);
}
