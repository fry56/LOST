/*
** EPITECH PROJECT, 2023
** remove_key_bind.c
** File description:
** desc
*/

#include <Utils/t_key.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>
#include <t_mem.h>

bool scene_remove_key_bind(scene *self, sfKeyCode key)
{
    list_foreach(self->list_keys, node) {
        if (((key_bind *)node->value)->key == key) {
            free(node->value);
            tlist_remove(self->list_keys, node);
            return true;
        }
    }
    return false;
}
