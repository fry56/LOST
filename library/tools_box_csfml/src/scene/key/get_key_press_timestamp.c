/*
** EPITECH PROJECT, 2023
** get_key_press_timestamp.c
** File description:
** desc
*/

#include <t_ctype.h>
#include <Utils/t_key.h>
#include <Class/t_scene.h>

tsize_t scene_get_key_press_timestamp(scene *self, sfKeyCode key)
{
    key_bind *key_datas;

    if ((key_datas = scene_get_key(self, key)) == NULL)
        return -1;
    return key_datas->timestamp;
}
