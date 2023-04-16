/*
** EPITECH PROJECT, 2023
** survivor_inventory_have_item.c
** File description:
** desc
*/

#include "t_ctype.h"
#include "survivor/survivor.h"
#include "inventory/inventory.h"
#include "inventory/inventory_items_config.h"

uint16_t inventory_have_item(survivor_s *survivor_datas, char *item_name)
{
    inventory_item_s *temp =
        inventory_get_item_by_name(survivor_datas->inventory_mgr, item_name);
    if (temp == NULL)
        return 0;
    return temp->amount;
}
