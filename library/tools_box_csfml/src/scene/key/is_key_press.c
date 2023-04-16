/*
** EPITECH PROJECT, 2023
** is_key_press.c
** File description:
** desc
*/

#include <t_ctype.h>
#include <Utils/t_key.h>
#include <Class/t_scene.h>

bool scene_is_key_press(scene *self, sfKeyCode key)
{
    key_bind *key_datas;

    if ((key_datas = scene_get_key(self, key)) == NULL)
        return false;
    return key_datas->is_press;
}
