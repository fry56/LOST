/*
** EPITECH PROJECT, 2023
** get_valide_offset.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <map/map.h>

static sfIntRect get_collider(box_collider_s *self, box_collider_s *temp)
{
    return (sfIntRect) {
        self->box.top - self->box.height < temp->box.top + temp->box.height,
        self->box.top + self->box.height > temp->box.top - temp->box.height,
        self->box.left - self->box.width < temp->box.left + temp->box.width,
        self->box.left + self->box.width > temp->box.left - temp->box.width,
    };
}

static void not_blocking_collider(box_collider_s *self, box_collider_s *temp,
    sfIntRect collide)
{
    t_list_node *temp_node;

    if (temp == self || temp->blocking)
        return;
    if ((temp_node = tlist_find(temp->list_sprite_inside, self->host))
        != NULL) {
        if ((collide.top && collide.left) && (collide.width && collide.height))
            return;
        tlist_remove(temp->list_sprite_inside, temp_node);
        if (temp->on_exit != NULL)
            temp->on_exit(self->host, temp);
        return;
    }
    if (collide.top && collide.left && collide.width && collide.height) {
        tlist_add(temp->list_sprite_inside, self->host);
        if (temp->on_enter != NULL)
            temp->on_enter(self->host, temp);
    }
}

static sfVector2f get_new_offset(box_collider_s *self, box_collider_s *temp,
    sfVector2f offset, sfVector2f new_offset)
{
    sfVector2f new_pos = (sfVector2f){self->box.left + offset.x,
        self->box.top + offset.y};
    sfIntRect collide = get_collider(self, temp);

    if (temp == self || !temp->blocking) {
        not_blocking_collider(self, temp, collide);
        return new_offset;
    }
    if (collide.top && collide.left) {
        if (new_pos.x - self->box.width < temp->box.left + temp->box.width &&
            new_pos.x + self->box.width > temp->box.left - temp->box.width &&
            collide.top && collide.left)
            new_offset.x = 0;
    }
    if (collide.width && collide.height)
        if (new_pos.y - self->box.height < temp->box.top + temp->box.height &&
            new_pos.y + self->box.height > temp->box.top - temp->box.height)
            new_offset.y = 0;
    return new_offset;
}

sfVector2f get_valide_offset(box_collider_s *self, sfVector2f offset)
{
    sfVector2f new_offset = offset;
    box_collider_s *temp;

    for (uint16_t i = 0; self->nbr_zone > i; i++) {
        list_foreach(self->current_zone[i], node) {
            temp = node->value;
            new_offset = get_new_offset(self, temp, offset, new_offset);
        }
    }
    return new_offset;
}
