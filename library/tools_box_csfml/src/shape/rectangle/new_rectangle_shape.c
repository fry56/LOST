/*
** EPITECH PROJECT, 2023
** new_cercle_shape.c
** File description:
** desc
*/

#include <Class/t_rectangle_shape.h>
#include <t_mem.h>

rectangle_shape *new_rectangle_shape(scene *scene_datas, sfVector2f pos,
    sfVector2f size, rgb rgb)
{
    rectangle_shape *temp = tcalloc(1, sizeof(rectangle_shape));

    temp->host = scene_datas;
    temp->pos = pos;
    temp->rectangle_shape_node =
        tlist_add(scene_datas->list_circle_shapes, temp);
    temp->sf_rectangle_shape = sfRectangleShape_create();
    sfRectangleShape_setPosition(temp->sf_rectangle_shape, pos);
    sfRectangleShape_setSize(temp->sf_rectangle_shape, size);
    temp->sf_color = sfColor_fromRGB(rgb.red, rgb.green, rgb.blue);
    sfRectangleShape_setOutlineColor(temp->sf_rectangle_shape, temp->sf_color);
    sfRectangleShape_setOutlineThickness(temp->sf_rectangle_shape, 2);
    return temp;
}
