/*
** EPITECH PROJECT, 2023
** inventory_get_item_by_name.c
** File description:
** desc
*/

#include "survivor/survivor.h"
#include "inventory/inventory.h"
#include "t_string.h"

inventory_item_s *inventory_get_item_by_name(inventory_mgr_s *inventory_mgr,
    char *item_name)
{
    for (int i = 0; i < NBR_ITEMS; ++i) {
        if (inventory_mgr->items[i].name == NULL)
            return NULL;
        if (tstr_cmp(inventory_mgr->items[i].name, item_name) == 0)
            return &inventory_mgr->items[i];
    }
    return NULL;
}
