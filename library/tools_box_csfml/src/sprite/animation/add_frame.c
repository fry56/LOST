/*
** EPITECH PROJECT, 2023
** add_frame.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <stdlib.h>
#include <t_mem.h>
#include <t_assert.h>

bool animation_add_frame(animation *self, sfIntRect rect)
{
    sfIntRect *temp_rect;

    tassert((temp_rect = tcalloc(1, sizeof(sfIntRect))) == NULL);
    *temp_rect = rect;
    tlist_add(self->list_frame_rect, temp_rect);
    return true;
}
