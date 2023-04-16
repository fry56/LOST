/*
** EPITECH PROJECT, 2023
** is_key_bind.c
** File description:
** desc
*/

#include <t_ctype.h>
#include <Class/t_window.h>
#include <Utils/t_key.h>
#include <Class/t_scene.h>

bool scene_is_key_bind(scene *self, sfKeyCode key)
{
    list_foreach(self->list_keys, node) {
        if (key == ((key_bind *)node->value)->key)
            return true;
    }
    return false;
}
