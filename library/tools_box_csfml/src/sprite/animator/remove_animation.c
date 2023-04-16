/*
** EPITECH PROJECT, 2022
** remove_animation.c
** File description:
** desc
*/

#include <Class/t_sprite_animator.h>
#include <Class/t_sprite_animation.h>

bool animator_remove_animation(animator *self, char *animation_name)
{
    t_hashmap_node *animation;

    if ((animation = thashmap_get(self->map_animation, animation_name)) == NULL)
        return false;
    if (self->played_animation == animation
        || self->default_animation == animation)
        return false;
    return thashmap_remove(self->map_animation, animation_name);
}
