/*
** EPITECH PROJECT, 2023
** get_by_flag.c
** File description:
** desc
*/

#include "Class/t_sprite.h"

sprite *sprite_get_by_flag(scene *scene_datas, char *flag)
{
    list_foreach(scene_datas->list_sprites, node)
        if (sprite_have_flag(node->value, flag))
            return node->value;
    return NULL;
}
