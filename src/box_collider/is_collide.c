/*
** EPITECH PROJECT, 2023
** is_collide.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <box_collider/box_collider.h>
#include <map/map.h>

bool is_collide(t_list *zone, sfIntRect box)
{
    sfVector2u collide = {0, 0};
    box_collider_s *temp;

    list_foreach(zone, node) {
        temp = node->value;
        if (box.left - box.width < temp->box.left + temp->box.width &&
            box.left + box.width > temp->box.left - temp->box.width)
            collide.x = 1;
        if (box.top - box.height < temp->box.top + temp->box.height &&
            box.top + box.height > temp->box.top - temp->box.height)
            collide.y = 1;
        if (collide.x && collide.y)
            return true;
    }
    return false;
}
