/*
** EPITECH PROJECT, 2022
** have_animation.c
** File description:
** desc
*/

#include <Class/t_sprite_animator.h>
#include <Class/t_sprite_animation.h>

t_hashmap_node *animator_have_animation(animator *self, char *animation_name)
{
    return thashmap_get(self->map_animation, animation_name);
}
