/*
** EPITECH PROJECT, 2023
** get_object_by_name.c
** File description:
** desc
*/

#include "inventory/inventory_items_config.h"
#include "t_string.h"

inventory_item_config_s *get_item_by_name(char *name)
{
    for (int i = 0; i < NBR_ITEMS; ++i) {
        if (tstr_cmp(inventory_items_config[i].name, name) == 0)
            return &inventory_items_config[i];
    }
    return NULL;
}
