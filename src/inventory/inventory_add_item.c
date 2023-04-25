/*
** EPITECH PROJECT, 2023
** survivor_inventory_add_item.c
** File description:
** desc
*/

#include "survivor/survivor.h"
#include "inventory/inventory.h"
#include "inventory/inventory_items_config.h"

bool inventory_add_item(survivor_s *survivor_datas, char *item_name,
    uint16_t amount)
{
    inventory_item_s *temp =
        inventory_get_item_by_name(survivor_datas->inventory_mgr, item_name);

    if (temp == NULL)
        return false;
    if (temp->amount + amount > inventory_items_config[temp->id].max_amount)
        return false;
    temp->amount += amount;
    inventory_hud_update(sprite_get_by_flag(
        survivor_datas->temp_datas->host->host, "inventory_hud"));
    return true;
}
