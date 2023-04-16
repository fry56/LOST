/*
** EPITECH PROJECT, 2022
** set_default.c
** File description:
** desc
*/

#include <Class/t_sprite_animator.h>
#include <Class/t_sprite_animation.h>
#include <t_mem.h>

bool animator_set_default(animator *self, char *animation_name)
{
    t_hashmap_node *animation_node;

    if ((animation_node = thashmap_get(self->map_animation
        , animation_name)) == NULL)
        return false;
    if (self->played_animation == NULL)
        self->played_animation = animation_node;
    self->default_animation = animation_node;
    return true;
}
