/*
** EPITECH PROJECT, 2023
** get_angle_offset.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <math.h>

sfVector2f get_angle_offset(sfVector2f start, sfVector2f end)
{
    float x = start.x - end.x;
    float y = start.y - end.y;
    float d = (float)sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));

    return (sfVector2f){-(x / d), -(y / d)};
}
