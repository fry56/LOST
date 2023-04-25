/*
** EPITECH PROJECT, 2023
** box_collider_destroy.c
** File description:
** desc
*/

#include <box_collider/box_collider.h>
#include <stdlib.h>

void box_collider_destroy(box_collider_s *box_collider)
{
    for (int i = 0; i < box_collider->nbr_zone; ++i) {
        tlist_remove(box_collider->node_current_zone[i]->host,
            box_collider->node_current_zone[i]);
    }
    if (box_collider->blocking == true) {
        tlist_clear(box_collider->list_sprite_inside);
        free(box_collider->list_sprite_inside);
    }
}
