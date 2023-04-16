/*
** EPITECH PROJECT, 2023
** new_box_collider.c
** File description:
** desc
*/

#include <box_collider/box_collider.h>
#include <t_mem.h>
#include <map/map.h>
#include <t_assert.h>

box_collider_s *new_box_collider(box_colliders_manager_s *mgr, sfIntRect pos,
    bool blocking)
{
    box_collider_s *temp = tcalloc(1, sizeof(box_collider_s));

    tassert(mgr == NULL);
    temp->box_colliders_mgr = mgr;
    temp->blocking = blocking;
    temp->nbr_zone = 0;
    temp->box = pos;
    update_zone_of_box_collider(mgr, temp);
    return temp;
}
