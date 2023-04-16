/*
** EPITECH PROJECT, 2022
** set_pos.c
** File description:
** desc
*/

#include "Class/t_sprite.h"
#include <SFML/Graphics.h>

void sprite_set_pos(sprite *self, sfVector2f pos)
{
    self->pos = pos;
    if (self->set_pos != NULL)
        self->set_pos(self, self->pos);
    sfSprite_setPosition(self->sf_sprite, self->pos);
}
