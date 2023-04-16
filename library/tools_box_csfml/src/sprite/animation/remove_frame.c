/*
** EPITECH PROJECT, 2023
** remove_frame.c
** File description:
** desc
*/

#include <Class/t_sprite.h>

bool animation_remove_frame(animation *self, size_t index)
{
    t_list_node *anim_node;

    if ((anim_node = tlist_get(self->list_frame_rect, index)) == NULL)
        return false;
    tlist_remove(self->list_frame_rect, anim_node);
    return true;
}
