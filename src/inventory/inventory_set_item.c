/*
** EPITECH PROJECT, 2023
** survivor_inventory_set_item.c
** File description:
** desc
*/

#include "survivor/survivor.h"
#include "inventory/inventory.h"
#include "inventory/inventory_items_config.h"

bool inventory_set_item(survivor_s *survivor_datas, char *item_name,
    uint16_t amount)
{
    inventory_item_s *temp =
        inventory_get_item_by_name(survivor_datas->inventory_mgr, item_name);

    if (temp == NULL)
        return false;
    if (temp->amount + amount < 0)
        return false;
    temp->amount = amount;
    return true;
}