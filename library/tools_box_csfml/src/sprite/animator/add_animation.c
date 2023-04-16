/*
** EPITECH PROJECT, 2022
** add_animation.c
** File description:
** desc
*/

#include <Class/t_sprite_animator.h>
#include <Class/t_sprite_animation.h>
#include <t_mem.h>

bool animator_add_animation(animator *self, animation *new_animation)
{
    t_hashmap_node *animation = thashmap_add(self->map_animation,
        new_animation->name,
        new_animation);
    if (animation == NULL)
        return false;
    if (self->default_animation == NULL)
        self->default_animation = animation;
    return true;
}
