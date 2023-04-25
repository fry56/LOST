/*
** EPITECH PROJECT, 2023
** t_shape.h
** File description:
** desc
*/
#ifndef t_circle_shape
    #define t_circle_shape

    #include "Utils/t_rgb.h"
    #include <SFML/Graphics.h>
    #include "t_ctype.h"
    #include "t_list.h"
    #include "t_scene.h"

    typedef struct circle_shape {
        scene *host;
        t_list_node *circle_shape_node;

        bool visible;
        void *datas;

        sfColor sf_color;
        sfVector2f pos;
        sfCircleShape *sf_circle_shape;
    } circle_shape;

    circle_shape *new_circle_shape(scene *scene_datas, sfVector2f pos,
        float radius, rgb rgb);
    void circle_shape_destroy(circle_shape *self);
#endif //t_circle_shape
