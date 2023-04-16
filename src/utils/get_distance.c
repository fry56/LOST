/*
** EPITECH PROJECT, 2023
** get_distance.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <math.h>

float get_distance(sfVector2f start, sfVector2f end)
{
    return (float)sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
}
