/*
** EPITECH PROJECT, 2023
** init_special_medkit.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <inventory/inventory_items_config.h>
#include <t_assert.h>
#include "interaction.h"
#include <t_mem.h>
#include <utils.h>

sprite *new_special_medkit_object(scene *scene_datas, sfVector2f pos)
{
    sprite *new_item;
    interaction_s *object_interaction;

    tassert((object_interaction = tcalloc(1, sizeof(interaction_s))) == NULL);
    new_item = new_sprite(scene_datas,
        "assets/sprites/items/items/item_medikit_zombie.png", 10);
    sprite_set_pos(new_item, pos);
    sprite_add_flag(new_item, "interactive");
    new_item->datas = object_interaction;
    new_item->destroy = special_medkit_object_destroy;
    object_interaction->host = new_item;
    object_interaction->interaction_dist = 100;
    object_interaction->onInteract = special_medkit_object_interact;
    return new_item;
}
