/*
** EPITECH PROJECT, 2023
** inventory_toggle.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <Class/t_text.h>
#include <survivor/survivor.h>
#include <t_mem.h>
#include <inventory/inventory.h>
#include <inventory/inventory_items_config.h>

void inventory_hud_toggle(scene *scene_datas)
{
    sprite *inventory_hud = sprite_get_by_flag(scene_datas, "inventory_hud");
    inventory_hud_s *hud = inventory_hud->datas;
    bool toggle = !inventory_hud->visible;
    inventory_hud_item_s *temp;
    sprite *survivor_sprite = sprite_get_by_flag(scene_datas, "survivor");

    inventory_hud->visible = toggle;
    if (survivor_sprite != NULL)
        ((survivor_s *)survivor_sprite->datas)->freeze = toggle;
    if (toggle)
        inventory_hud_update(inventory_hud);
    for (int i = 0; i < NBR_ITEMS; ++i) {
        if (inventory_items_config[i].name == NULL)
            return;
        temp = &hud->items[i];
        if (temp->button != NULL)
            temp->button->visible = toggle;
        temp->item->visible = toggle;
        temp->amount->visible = toggle;
    }
}
