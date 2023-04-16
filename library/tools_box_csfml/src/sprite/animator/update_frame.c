/*
** EPITECH PROJECT, 2022
** update_frame.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <stdlib.h>
#include <Class/t_sprite_animator.h>

static bool is_freeze(animator *self)
{
    animation *anim = self->played_animation->value;

    if (self->animation_frame == (int)(anim->list_frame_rect->length) - 1 &&
        anim->end_freeze)
        return true;
    return false;
}

int animator_update_frame(animator *self, sfClock *clock)
{
    animation *anim;

    if (self->played_animation == NULL)
        return false;
    anim = self->played_animation->value;
    if (self->last_clock_update + (int)(anim->frame_rate * 10000)
        >= sfClock_getElapsedTime(clock).microseconds || is_freeze(self))
        return false;
    self->last_clock_update = sfClock_getElapsedTime(clock).microseconds;
    if (self->animation_frame > (int)(anim->list_frame_rect->length) - 1) {
        self->animation_frame = 0;
        animator_callback(self, anim->name);
        if (!anim->loop && self->played_animation != self->default_animation)
            animator_play_animation(self,
                ((animation *)self->default_animation->value)->name);
        return true;
    }
    self->animation_frame++;
    return true;
}
