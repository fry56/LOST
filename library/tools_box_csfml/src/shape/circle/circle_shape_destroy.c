/*
** EPITECH PROJECT, 2023
** circle_shape_destroy.c
** File description:
** desc
*/

#include <Class/t_circle_shape.h>

void circle_shape_garbadg_destroy(void *datas)
{
    circle_shape *self = datas;
    sfCircleShape_destroy(self->sf_circle_shape);
    tlist_remove(self->circle_shape_node->host, self->circle_shape_node);
}

void circle_shape_destroy(circle_shape *self)
{
    window_add_garbage(self->host->host, self->circle_shape_node,
        circle_shape_garbadg_destroy);
}
