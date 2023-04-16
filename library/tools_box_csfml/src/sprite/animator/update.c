/*
** EPITECH PROJECT, 2023
** update.c
** File description:
** desc
*/

#include "Class/t_sprite.h"
#include <stdio.h>
#include "Class/t_window.h"
#include <Class/t_sprite_animator.h>

void update_sprite_animator(sprite *sprite, sfClock *clock)
{
    animator *animator = sprite->animator;
    animation *animation;
    t_list_node *temp_rect;

    if (sprite->animator == NULL)
        return;
    if (animator_update_frame(animator, clock)) {
        animation = animator->played_animation->value;
        if ((temp_rect = tlist_get(animation->list_frame_rect,
            animator->animation_frame)) == NULL)
            return;
        sfSprite_setTextureRect(sprite->sf_sprite,
            *(sfIntRect *)temp_rect->value);
    }
}
