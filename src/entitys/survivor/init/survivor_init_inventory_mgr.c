/*
** EPITECH PROJECT, 2023
** survivor_init_inventory_mgr.c
** File description:
** desc
*/

#include <survivor/survivor.h>
#include <inventory/inventory.h>
#include <inventory/inventory_items_config.h>
#include <t_mem.h>
#include <t_assert.h>

void survivor_init_inventory_mgr(survivor_s *survivor_datas)
{
    tassert((survivor_datas->inventory_mgr =
        tcalloc(1, sizeof(inventory_mgr_s))) == NULL);
    survivor_datas->inventory_mgr->host = survivor_datas;
    survivor_datas->inventory_mgr->timestamp_wait = 0;
    for (int i = 0; inventory_items_config[i].name != NULL; ++i) {
        survivor_datas->inventory_mgr->items[i] = (inventory_item_s){
            i,
            inventory_items_config[i].name,
            0
        };
    }
}
