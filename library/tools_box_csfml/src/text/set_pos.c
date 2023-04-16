/*
** EPITECH PROJECT, 2022
** set_pos.c
** File description:
** desc
*/

#include <Class/t_text.h>

void text_set_pos(text *self, sfVector2f pos)
{
    self->pos = pos;
    if (self->set_pos != NULL)
        self->set_pos(self, self->pos);
    sfText_setPosition(self->sf_text, self->pos);
}
