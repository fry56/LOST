/*
** EPITECH PROJECT, 2023
** box_collider_destroy.c
** File description:
** desc
*/

#include <box_collider/box_collider.h>

void box_collider_destroy(box_collider_s *box_collider)
{
    for (int i = 0; i < box_collider->nbr_zone; ++i) {
        tlist_remove(box_collider->node_current_zone[i]->host,
            box_collider->node_current_zone[i]);
    }
}
