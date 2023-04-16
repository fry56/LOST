/*
** EPITECH PROJECT, 2022
** set_pos.c
** File description:
** desc
*/

#include "Class/t_text.h"
#include <SFML/Graphics.h>

void text_move(text *self, sfVector2f pos)
{
    self->pos = (sfVector2f){self->pos.x + pos.x, self->pos.y + pos.y};
    if (self->move != NULL)
        self->move(self, self->pos);
    sfText_move(self->sf_text, pos);
}
