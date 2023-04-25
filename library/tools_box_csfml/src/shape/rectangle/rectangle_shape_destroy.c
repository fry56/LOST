/*
** EPITECH PROJECT, 2023
** circle_shape_destroy.c
** File description:
** desc
*/

#include <Class/t_rectangle_shape.h>

void rectangle_shape_garbadg_destroy(void *datas)
{
    rectangle_shape *self = datas;
    sfRectangleShape_destroy(self->sf_rectangle_shape);
    tlist_remove(self->rectangle_shape_node->host,
        self->rectangle_shape_node);
}

void rectangle_shape_destroy(rectangle_shape *self)
{
    window_add_garbage(self->host->host, self->rectangle_shape_node,
        rectangle_shape_garbadg_destroy);
}
