/*
** EPITECH PROJECT, 2023
** new_raycast.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <math.h>
#include <utils.h>

bool raycast(sfVector2f start, sfVector2f end, double angle, float clerance)
{
    angle = angle * (M_PI / 180);
    float temp_dist = get_distance(start, end);
    sfVector2f temp_estimated = (sfVector2f){
        start.x + cos(angle) * temp_dist,
        start.y + sin(angle) * temp_dist
    };

    if (temp_estimated.x + clerance < end.x ||
        temp_estimated.x - clerance > end.x)
        return false;
    if (temp_estimated.y + clerance < end.y ||
        temp_estimated.y - clerance > end.y)
        return false;
    return true;
}
