/*
** EPITECH PROJECT, 2023
** survivor_inventory_use_item.c
** File description:
** desc
*/

#include "survivor/survivor.h"
#include "inventory/inventory.h"
#include "inventory/inventory_items_config.h"

bool inventory_use_item(survivor_s *survivor_datas, char *item_name)
{
    window *window_datas = survivor_datas->host->host->host;
    inventory_item_s *temp = inventory_get_item_by_name(
        survivor_datas->inventory_mgr, item_name);
    uint64_t timestamp =
        sfClock_getElapsedTime(window_datas->global_clock).microseconds;

    if (temp == NULL || timestamp <
        survivor_datas->inventory_mgr->timestamp_wait)
        return false;
    if (inventory_items_config[temp->id].use == NULL)
        return false;
    inventory_items_config[temp->id].use(survivor_datas->inventory_mgr, temp);
    return true;
}
