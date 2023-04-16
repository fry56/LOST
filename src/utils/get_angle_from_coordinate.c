/*
** EPITECH PROJECT, 2023
** get_angle_from_coordinate.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <math.h>

float get_angle_from_coordinate(sfVector2f point_a, sfVector2f point_b)
{
    float dx = point_b.x - point_a.x;
    float dy = point_b.y - point_a.y;
    float radians = atan2f(dx, dy);

    if (radians < 0.0)
        radians = fabs(radians);
    else
        radians = 2 * M_PI - radians;
    return (float)(180.0 / M_PI * radians);
}
