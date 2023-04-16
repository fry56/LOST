/*
** EPITECH PROJECT, 2022
** set_font_size.c
** File description:
** desc
*/

#include <Class/t_text.h>

void text_set_font_size(text *self, uint32_t font_size)
{
    sfText_setCharacterSize(self->sf_text, font_size);
}
