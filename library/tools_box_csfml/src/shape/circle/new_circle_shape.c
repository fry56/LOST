/*
** EPITECH PROJECT, 2023
** new_cercle_shape.c
** File description:
** desc
*/

#include <Class/t_circle_shape.h>
#include <t_mem.h>

circle_shape *new_circle_shape(scene *scene_datas, sfVector2f pos,
    float radius, rgb rgb)
{
    circle_shape *temp = tcalloc(1, sizeof(circle_shape));

    temp->host = scene_datas;
    temp->pos = pos;
    temp->circle_shape_node = tlist_add(scene_datas->list_circle_shapes, temp);
    temp->sf_circle_shape = sfCircleShape_create();
    sfCircleShape_setPosition(temp->sf_circle_shape, pos);
    sfCircleShape_setRadius(temp->sf_circle_shape, radius);
    temp->sf_color = sfColor_fromRGB(rgb.red, rgb.green, rgb.blue);
    sfCircleShape_setOutlineColor(temp->sf_circle_shape, temp->sf_color);
    sfCircleShape_setOutlineThickness(temp->sf_circle_shape, 2);
    return temp;
}
