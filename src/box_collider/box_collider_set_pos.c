/*
** EPITECH PROJECT, 2023
** box_collider_set_pos.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <box_collider/box_collider.h>
#include <map/map.h>
#include <t_assert.h>

void box_collider_set_pos(box_collider_s *box_collider, sfVector2f pos)
{
    box_collider->box = (sfIntRect){(int)pos.x, (int)pos.y,
        box_collider->box.width, box_collider->box.height};
    tassert(box_collider->box_colliders_mgr == NULL);
    update_zone_of_box_collider(box_collider->box_colliders_mgr, box_collider);
}
