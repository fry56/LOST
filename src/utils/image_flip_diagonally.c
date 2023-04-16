/*
** EPITECH PROJECT, 2023
** image_flipDiagonally .c
** File description:
** desc
*/

#include <Class/t_sprite.h>

sfImage *image_flip_diagonally(sfImage *source)
{
    sfVector2u size = sfImage_getSize(source);
    sfVector2u int_pos = {0, 0}, rev_pos;
    sfImage *temp_img = sfImage_create(size.x, size.y);
    sfColor temp_color;

    for (uint32_t i = 0; i < size.x * size.y; ++i, int_pos.x++) {
        if (int_pos.x == size.x)
            int_pos = (sfVector2u){0, int_pos.y + 1};
        rev_pos = (sfVector2u){size.y - int_pos.y, size.x - int_pos.x};
        temp_color = sfImage_getPixel(source, int_pos.x, int_pos.y);
        sfImage_setPixel(temp_img, rev_pos.x - 1, rev_pos.y - 1, temp_color);
    }
    return temp_img;
}
