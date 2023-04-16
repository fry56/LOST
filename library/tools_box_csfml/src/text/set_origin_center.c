/*
** EPITECH PROJECT, 2022
** set_origin_center.c
** File description:
** desc
*/

#include <Class/t_text.h>

void text_set_origin_center(text *self)
{
    sfFloatRect text_bounds = sfText_getGlobalBounds(self->sf_text);

    sfText_setOrigin(self->sf_text
        , (sfVector2f){(text_bounds.width / 2), (text_bounds.height / 2)});
}
