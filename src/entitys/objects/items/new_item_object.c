/*
** EPITECH PROJECT, 2023
** new_item_object.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <inventory/inventory_items_config.h>
#include <t_assert.h>
#include "interaction.h"
#include <t_mem.h>
#include <utils.h>

sprite *new_item_object(scene *scene_datas, sfVector2f pos, float angle,
    char *name)
{
    inventory_item_config_s *config = get_item_by_name(name);
    sprite *new_item;
    interaction_s *object_interaction;
    item_object_s *item_object;

    tassert(config == NULL);
    tassert((object_interaction = tcalloc(1, sizeof(interaction_s))) == NULL);
    tassert((item_object = tcalloc(1, sizeof(item_object_s))) == NULL);
    new_item = new_sprite(scene_datas, config->path, 10);
    sprite_set_pos(new_item, pos);
    sprite_add_flag(new_item, "interactive");
    sfSprite_setRotation(new_item->sf_sprite, angle);
    new_item->datas = object_interaction;
    new_item->destroy = item_object_destroy;
    object_interaction->host = new_item;
    object_interaction->datas = item_object;
    item_object->name = name;
    object_interaction->interaction_dist = 100;
    object_interaction->onInteract = item_object_interact;
    return new_item;
}
