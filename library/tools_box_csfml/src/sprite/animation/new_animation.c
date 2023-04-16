/*
** EPITECH PROJECT, 2022
** new_animation.c
** File description:
** desc
*/

#include <Class/t_sprite_animation.h>
#include <stdlib.h>
#include <t_mem.h>
#include <t_assert.h>

animation *new_animation(char *name, char *path, bool loop, float frame_rate)
{
    animation *new_animation = tcalloc(1, sizeof(animation));

    t_assert(new_animation == NULL);
    new_animation->sf_texture = NULL;
    new_animation->name = name;
    new_animation->loop = loop;
    new_animation->end_freeze = false;
    new_animation->frame_rate = frame_rate;
    new_animation->list_frame_rect = tlist_new();
    if (path != NULL)
        tassert((new_animation->sf_texture =
            sfTexture_createFromFile(path, NULL)) == NULL);
    return new_animation;
}
