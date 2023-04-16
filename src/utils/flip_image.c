/*
** EPITECH PROJECT, 2023
** flip_image.c
** File description:
** desc
*/

#include <Class/t_sprite.h>

void flip_image(sfImage *tiled_img, bool horizontally,
    bool vertically)
{
    if (horizontally)
        sfImage_flipHorizontally(tiled_img);
    if (vertically)
        sfImage_flipVertically(tiled_img);
}
