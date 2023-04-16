/*
** EPITECH PROJECT, 2022
** set_font_color.c
** File description:
** desc
*/
#include <Utils/t_rgb.h>
#include <Class/t_text.h>

void text_set_font_color(text *self, rgb rgb)
{
    self->sf_color = sfColor_fromRGB(rgb.red, rgb.green, rgb.blue);
    sfText_setColor(self->sf_text, self->sf_color);
}
