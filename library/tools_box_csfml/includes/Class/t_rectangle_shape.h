/*
** EPITECH PROJECT, 2023
** t_shape.h
** File description:
** desc
*/
#ifndef t_rectangle_shape
    #define t_rectangle_shape

    #include "Utils/t_rgb.h"
    #include <SFML/Graphics.h>
    #include "t_ctype.h"
    #include "t_list.h"
    #include "t_scene.h"

    typedef struct rectangle_shape {
        scene *host;
        t_list_node *rectangle_shape_node;

        bool visible;
        void *datas;

        sfColor sf_color;
        sfVector2f pos;
        sfRectangleShape *sf_rectangle_shape;
    } rectangle_shape;

    rectangle_shape *new_rectangle_shape(scene *scene_datas, sfVector2f pos,
        sfVector2f size, rgb rgb);
    void rectangle_shape_destroy(rectangle_shape *self);
#endif //t_rectangle_shape
