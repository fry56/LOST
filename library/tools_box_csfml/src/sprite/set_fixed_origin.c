/*
** EPITECH PROJECT, 2023
** set_fixed_origin.c
** File description:
** desc
*/

#include <t_ctype.h>
#include <Class/t_sprite.h>

void sprite_set_fixed_origin(sprite *self, sfVector2f origin)
{
    sfSprite_setOrigin(self->sf_sprite, origin);
    self->fixed_origin = true;
}
