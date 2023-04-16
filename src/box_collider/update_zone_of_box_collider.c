/*
** EPITECH PROJECT, 2023
** get_zone_by_pos.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <box_collider/box_collider.h>
#include <map/map.h>
#include <t_assert.h>

static void remove_zone(box_collider_s *box_collider)
{
    for (int i = 0; i < box_collider->nbr_zone; ++i) {
        tlist_remove(box_collider->current_zone[i],
            box_collider->node_current_zone[i]);
        box_collider->current_zone[i] = NULL;
    }
    box_collider->nbr_zone = 0;
}

static void insert_zone(box_collider_s *collider, t_list *temp)
{
    for (int i = 0; i < collider->nbr_zone; ++i) {
        if (collider->current_zone[i] == temp)
            return;
    }
    collider->current_zone[collider->nbr_zone++] = temp;
    tassert((collider->node_current_zone[collider->nbr_zone - 1] =
        tlist_add(temp, collider)) == NULL);
}

void update_zone_of_box_collider(box_colliders_manager_s *mgr,
    box_collider_s *collider)
{
    t_list *temp;
    sfVector2i index = {-1, -1};

    if (collider->nbr_zone > 0)
        remove_zone(collider);
    for (int i = 0; i < 4; ++i, index.x = -index.x) {
        if ((temp = get_zone_by_pos(mgr, (sfVector2f){collider->box.left +
            (collider->box.width * index.x), collider->box.top +
            (collider->box.height * index.y) })) != NULL) {
            insert_zone(collider, temp);
        }
        if (index.x == 1)
            index = (sfVector2i){1, 1};
    }
}
