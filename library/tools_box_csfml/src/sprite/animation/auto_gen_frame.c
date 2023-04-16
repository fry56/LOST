/*
** EPITECH PROJECT, 2023
** auto_gen_frame.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <stdlib.h>
#include <t_mem.h>
#include <t_assert.h>

bool animation_auto_gen_frame(animation *self, int nbr_sprites
    , int nbr_sprite_per_line, sfIntRect rect_start)
{
    sfIntRect *temp_rect;
    int line_index;

    for (int i = 0; i < nbr_sprites; ++i) {
        tassert((temp_rect = tcalloc(1, sizeof(sfIntRect))) == NULL);
        line_index = abs(i / nbr_sprite_per_line);
        *temp_rect = rect_start;
        temp_rect->top += rect_start.height * line_index;
        temp_rect->left *= rect_start.width *
            (i - (line_index * nbr_sprite_per_line));
        tlist_add(self->list_frame_rect, temp_rect);
    }
    return true;
}
