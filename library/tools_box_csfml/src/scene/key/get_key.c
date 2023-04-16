/*
** EPITECH PROJECT, 2023
** get_key.c
** File description:
** desc
*/

#include <t_ctype.h>
#include <Class/t_window.h>
#include <Utils/t_key.h>
#include <Class/t_scene.h>

key_bind *scene_get_key(scene *self, sfKeyCode key)
{
    list_foreach(self->list_keys, node) {
        if (key == ((key_bind *)node->value)->key)
            return node->value;
    }
    return NULL;
}
